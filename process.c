#include "prototyper.h"

void DelayFor18TCY (void)		
{
	Delay10TCYx (2);		        // a delay of 20 TCY
}

void DelayPORXLCD (void) 		
{
	Delay1KTCYx (15);     			// a delay of 15ms at 4 MHZ
}

void DelayXLCD (void) 			
{
	Delay1KTCYx (5);				// a delay of 5ms at 4 MHZ  
}

unsigned char SlaveAck (void)
{	
	I2C_CheckBus (); 	
	
	if (SSPCON2bits.ACKSTAT == 0)	// Acknowledge was received from Slave
		return 1; 
		
	else							// Acknowledge was NOT received from slave
		return 0; 		
}

void MasterNACK (void)
{
	I2C_CheckBus ();
	
	SSPCON2bits.ACKDT = 1;           // Set a NACK condition and give control of the bus
    SSPCON2bits.ACKEN = 1;           // Initiate an Acknowledge sequence on SDA & SCL pins 
    while (SSPCON2bits.ACKEN); 	 	 // wait until ACK sequence is over
}

void MasterACK (void)
{
	I2C_CheckBus ();
	
	SSPCON2bits.ACKDT = 0;           // Set a ACK condition and hold control of the bus
    SSPCON2bits.ACKEN = 1;           // Initiate an Acknowledge sequence on SDA & SCL pins 
    while (SSPCON2bits.ACKEN); 	 	 // wait until ACK sequence is over
}


void I2C_MASTER_Write (unsigned char Device, unsigned char InternalAdd, unsigned char Data)
{
	I2C_Start (); 							// Initiate a Start Condition on the Bus 
	
	I2C_Write ((Device << 1) | 0x00 );		// First Shift the 7-bit Device Address and 
											// OR it with 0 (in our case to write to it). 
											// As per the Device's TRM,  ( OR with 1 For Read & OR with 0 For Write)
	
	if (SlaveAck ())						// Verify there is a slave device with this address [if Device's Address is valid]			
	{
		I2C_Write (InternalAdd); 				// Specify the Internal Address You want to Communicate Wtih 
		
		if (SlaveAck ())							// Verify that the internal address[InternalAdd] is a valid address
		{
			I2C_Write (Data);							// Write the Data you want to Write to the internal Register 
			
			if (SlaveAck ())								// Verify that the slave has acknowledged the data written to it 
			{
				I2C_Stop ();									// Initiate a Stop Condition on the Bus 
				
					Delay1KTCYx (5);								// A Delay for an internal Write to the EEPROM			
			}		
		}
	}
}

unsigned char I2C_MASTER_Read (unsigned char Device, unsigned char InternalAdd)
{
	unsigned char ReadValue; 
	
	I2C_Start (); 							// Initiate a Start Condition on the Bus 
	
	I2C_Write ((Device << 1) | 0x00 );		// First Shift the 7-bit Device Address and 
											// OR it with 0 (in our case to write to it). 
											// As per the TC74's TRM,  ( OR with 1 For Read & OR with 0 For Write)
											// Here we are Writing to the Device that we Want to Communicate wiz one of it's Registers
											
	if (SlaveAck ())						// Verify there is a slave device with this address [if Device's Address is valid]
	{
		I2C_Write (InternalAdd); 				// Specify the Internal Address You want to Communicate Wtih	
		
		if (SlaveAck ())							// Verify that the internal address[InternalAdd] is a valid address in WriteMode
		{
			I2C_Start (); 							// Initiate a Start Condition on the Bus 
	
//			I2C_RepStart (); 						// Initiate a Repeated Start Condition on the Bus 
			
			I2C_Write ((Device << 1) | 0x01);		// First Shift the 7-bit Device Address and OR it with 1
													// Here We are telling the Device that we want to read from the specific 
												    // Internal address mentioned above. 
												    // We are ORing The Device With 1 For reasons mentioned above!! [the TC74's TRM!]
													// If there is a slave device with this address	
													
			if (SlaveAck ())						// Verify that the internal address[InternalAdd] is a valid address in ReadMode
			{
				ReadValue = I2C_Read ();				// Read the Data stored in the SSPBUF Register 
				
				MasterNACK (); 							// Giveup Control of the bus 
	
				I2C_Stop ();							// Initiate a Stop Condition on the Bus
	
				return ReadValue; 						// Return Value read forn the internal Register 
			}
		}
	}										 
}

