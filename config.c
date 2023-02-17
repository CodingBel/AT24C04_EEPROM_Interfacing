#include "prototyper.h"

void PortInit (void)
{
	TRISCbits.TRISC3 = 1;			// Make SCL pin input (this will turn it to an open drain pin automatically)
	TRISCbits.TRISC4 = 1; 			// Make SDA pin input (this will turn it to an open drain pin automatically)
	
	TRISCbits.TRISC2 = 0; 			// Pin used to check Pwr on Ckt
	LATCbits.LATC2   = 1; 			//
		
	TRISD = 0x00; 					// PORT for LCD
	LATD  = 0x00; 					// 
}

void LCD_Init (void)
{
	OpenXLCD (FOUR_BIT & LINES_5X7);
	while (BusyXLCD()); 
	WriteCmdXLCD (DISPLAY_ON);  		 // TURN DISPLAY ON cursor off
	while (BusyXLCD()); 									
	WriteCmdXLCD (0x80);				 // begin at the first line 
	while (BusyXLCD()); 
	WriteCmdXLCD (CLRSCR);	 			 // clear the lcd screen
}

void I2C_Init (void)
{
	SSPSTATbits.SMP   = 0; 	// Enable I2C For High Speed Mode (i.e 400KHz)
	
	SSPCON1bits.SSPM3 = 1;	// Enable I2C in Master Mode
	SSPCON1bits.SSPM2 = 0;	//
	SSPCON1bits.SSPM1 = 0;	//
	SSPCON1bits.SSPM0 = 0; 	//
	
	SSPCON1bits.SSPEN = 1; 	// Enable I2C Mode & Configure SDA and SCL Pins as Open-Drain 
}

void I2C_CheckBus (void)
{
	while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04)); 
	// [SSPSTAT & 0x04]: Checks if A TRANSMIT is in progress
	// [SSPCON2 & 0x1F]: Checks if there is any kind of action that might make z BUS busy (non idle)
}

void I2C_Start (void)
{
	I2C_CheckBus();						// Check if z bus is idle
	SSPCON2bits.SEN = 1;				// Initiate a Start condition on z BUS
	while (SSPCON2bits.SEN);			// wait until start sequence is over 
}

void I2C_RepStart (void)
{
	I2C_CheckBus();						// Check if z bus is idle
	SSPCON2bits.RSEN = 1;				// Initiate a Repeated_Start condition on z BUS
	while (SSPCON2bits.SEN);			// wait until start sequence is over 
}

void I2C_Stop (void)
{
	I2C_CheckBus();						// Check if z bus is idle
	SSPCON2bits.PEN = 1;				// Initiate a stoP condition on z BUS
	while (SSPCON2bits.PEN);			// wait until stop sequence is over	
}

void I2C_Write (unsigned char Wvalue)
{
	I2C_CheckBus();						// Check if z bus is idle
	SSPBUF = Wvalue;					// Load the Incoming Data to the SSPBUF Register 
	
	if (SSPCON1bits.WCOL)				// If there is a write collision @ the I2C bus
	{
		I2C_CheckBus();					// Check if z bus is idle
		SSPCON1bits.WCOL = 0; 			// Clear this bit in Software
		
		I2C_CheckBus();					// Check if z bus is idle
		SSPBUF = Wvalue;				// RELOAD the Incoming Data to the SSPBUF Register 
	}
}

unsigned char I2C_Read  (void)
{
	unsigned char Incoming_value;
	
	I2C_CheckBus();						// Check if z bus is idle
	SSPCON2bits.RCEN = 1; 				// Enable receive Mode for the I2C Master  
	
	I2C_CheckBus();						// Check if z bus is idle
	Incoming_value = SSPBUF; 			// load the data Stored in the SSPBUF Register
	
	return Incoming_value;				// Return Value [i.e Return Value Stored in the SSPBUF]
}





