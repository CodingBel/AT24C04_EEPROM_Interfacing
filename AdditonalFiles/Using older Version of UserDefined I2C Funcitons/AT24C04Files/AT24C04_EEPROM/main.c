/*
* This Code is used to interface a 4Kbit EEPROM (Atmel 24C04) to a PIC18f4520 MCU
* The I2C Communication protocol is used to interface the EEPROM & the MCU
* The Project Writes a String of Characters to the EEPROM's Non-Volatile Memory 
* Then Fetches the strings and Displays them on a 20x4 LCD Display. 
*
* The Project uses a XTAL of 4MHZ

* Since the EEPROM, Atmel 24C04 is not found in proteus, The project could not be Simmulated
* Though it was tested on Hardware and works perfectly. 
* A video is attached within this folder 
*
* Author: ABEL ASHENAFI
* Date: August 30, 2019 
*
* Version 1.0   
*/

#include"prototyper.h"

#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config OSC = HS


void main (void)
{
	unsigned char Data0, Data1, Data2, Data3, Data4, Data5, Data6, Data7, Data8, Data9;
	unsigned char i;   
	unsigned char Name [] = "Take Risks"; 
	
	PortInit (); 
	I2C_Init (); 
	LCD_Init ();

	i = 0; 
	while (Name [i] != '\0')						// This fragment of code is used to write characters 				
	{												// To the EEPROM's Non-Volatile Memory until a Null Character is Found 
		I2C_MASTER_Write(AT24C04, i, Name [i]);
		i++; 
	}
			
	Data0 = I2C_MASTER_Read (AT24C04, Byte0);   	// Reading characters From the EEPROM's Non-volatile Memory 
	Data1 = I2C_MASTER_Read (AT24C04, Byte1);		//
	Data2 = I2C_MASTER_Read (AT24C04, Byte2);   	//
	Data3 = I2C_MASTER_Read (AT24C04, Byte3);		//
		
	Data4 = I2C_MASTER_Read (AT24C04, Byte4);   	//
	Data5 = I2C_MASTER_Read (AT24C04, Byte5);		//
	Data6 = I2C_MASTER_Read (AT24C04, Byte6);   	//
	Data7 = I2C_MASTER_Read (AT24C04, Byte7);		//
	
	Data8 = I2C_MASTER_Read (AT24C04, Byte8);		//
	Data9 = I2C_MASTER_Read (AT24C04, Byte9);		//
	
	
	while (BusyXLCD());	
	WriteDataXLCD (Data0); 							// Displaying characters from the EEPROM's Non-Volatile Memory 
	Delay10KTCYx (100);
	while (BusyXLCD());	
	WriteDataXLCD (Data1); 							//
	Delay10KTCYx (100);
	while (BusyXLCD());	
	WriteDataXLCD (Data2); 							//
	Delay10KTCYx (100);
	while (BusyXLCD());	
	WriteDataXLCD (Data3); 							//
	Delay10KTCYx (100);
	
	
	while (BusyXLCD());	
	WriteDataXLCD (Data4); 							//
	Delay10KTCYx (100);
	while (BusyXLCD());	
	WriteDataXLCD (Data5); 							//
	Delay10KTCYx (100);
	while (BusyXLCD());	
	WriteDataXLCD (Data6); 							//
	Delay10KTCYx (100);
	while (BusyXLCD());	
	WriteDataXLCD (Data7); 							//
	Delay10KTCYx (100);
	
	WriteDataXLCD (Data8); 							//
	Delay10KTCYx (100);
	while (BusyXLCD());	
	WriteDataXLCD (Data9); 							// 
	Delay10KTCYx (100);
	
	while (1)
	{
		// Do Nothing Here
	} 
}


