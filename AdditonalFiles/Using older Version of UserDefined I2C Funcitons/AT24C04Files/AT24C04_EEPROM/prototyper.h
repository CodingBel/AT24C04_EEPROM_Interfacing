#include <p18f4520.h>
#include <delays.h>
#include <xlcd.h>

#define AT24C04 0x56 

#define Byte0   0x00 
#define Byte1   0x01 
#define Byte2   0x02 
#define Byte3   0x03 
#define Byte4   0x04 
#define Byte5   0x05 
#define Byte6   0x06 
#define Byte7   0x07 
#define Byte8   0x08 
#define Byte9   0x09 

#define CLRSCR 		0x01
#define DISPLAY_ON 	0x0C
#define DISPLAY_OFF 0x08

void PortInit (void);


void LCD_Init (void);
void LCD_Stuff (void); 

void I2C_Init (void);
void I2C_CheckBus (void);
void I2C_Start (void);
void I2C_RepStart (void);
void I2C_Stop (void);

void I2C_Write (unsigned char);
unsigned char I2C_Read  (void);

void I2C_MASTER_Write (unsigned char, unsigned char, unsigned char); 
unsigned char I2C_MASTER_Read (unsigned char, unsigned char);

