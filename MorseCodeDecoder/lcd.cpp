/*
 * lcd.cpp
 *
 * Created: 07-03-2015 05:52:49 PM
 *  Author: Ajinkya
 */ 
#include "lcd.h"
#include "stdlib.h"
LCD::LCD()
{
	portInit();
	set4bit();
	init();
}
//Function to configure LCD port
void LCD::portConfig (void)
{
	DDRC = DDRC | 0xF7; //all the LCD pin's direction set as output
	PORTC = PORTC & 0x80; // all the LCD pins are set to logic 0 except PORTC 7
}

//Function to Initialize PORTS
void LCD::portInit()
{
	portConfig();
}

//Function to Reset LCD
void LCD::set4bit()
{
	_delay_ms(1);

	cbit(lcd_port,RS);				//RS=0 --- Command Input
	cbit(lcd_port,RW);				//RW=0 --- Writing to LCD
	lcd_port = 0x30;				//Sending 3
	sbit(lcd_port,EN);				//Set Enable Pin
	_delay_ms(5);					//Delay
	cbit(lcd_port,EN);				//Clear Enable Pin

	_delay_ms(1);

	cbit(lcd_port,RS);				//RS=0 --- Command Input
	cbit(lcd_port,RW);				//RW=0 --- Writing to LCD
	lcd_port = 0x30;				//Sending 3
	sbit(lcd_port,EN);				//Set Enable Pin
	_delay_ms(5);					//Delay
	cbit(lcd_port,EN);				//Clear Enable Pin

	_delay_ms(1);

	cbit(lcd_port,RS);				//RS=0 --- Command Input
	cbit(lcd_port,RW);				//RW=0 --- Writing to LCD
	lcd_port = 0x30;				//Sending 3
	sbit(lcd_port,EN);				//Set Enable Pin
	_delay_ms(5);					//Delay
	cbit(lcd_port,EN);				//Clear Enable Pin

	_delay_ms(1);

	cbit(lcd_port,RS);				//RS=0 --- Command Input
	cbit(lcd_port,RW);				//RW=0 --- Writing to LCD
	lcd_port = 0x20;				//Sending 2 to initialise LCD 4-bit mode
	sbit(lcd_port,EN);				//Set Enable Pin
	_delay_ms(1);					//Delay
	cbit(lcd_port,EN);				//Clear Enable Pin

	
}

//Function to Initialize LCD
void LCD::init()
{
	_delay_ms(1);

	writeCommand(0x28);			//LCD 4-bit mode and 2 lines.
	writeCommand(0x01);
	writeCommand(0x06);
	writeCommand(0x0E);
	writeCommand(0x80);
	
}


//Function to Write Command on LCD
void LCD::writeCommand(unsigned char cmd)
{
	unsigned char temp;
	temp = cmd;
	temp = temp & 0xF0;
	lcd_port &= 0x0F;
	lcd_port |= temp;
	cbit(lcd_port,RS);
	cbit(lcd_port,RW);
	sbit(lcd_port,EN);
	_delay_ms(5);
	cbit(lcd_port,EN);
	
	cmd = cmd & 0x0F;
	cmd = cmd<<4;
	lcd_port &= 0x0F;
	lcd_port |= cmd;
	cbit(lcd_port,RS);
	cbit(lcd_port,RW);
	sbit(lcd_port,EN);
	_delay_ms(5);
	cbit(lcd_port,EN);
}

//Function to Write Data on LCD
void LCD::writeChar(char letter)
{
	char temp;
	temp = letter;
	temp = (temp & 0xF0);
	lcd_port &= 0x0F;
	lcd_port |= temp;
	sbit(lcd_port,RS);
	cbit(lcd_port,RW);
	sbit(lcd_port,EN);
	_delay_ms(5);
	cbit(lcd_port,EN);

	letter = letter & 0x0F;
	letter = letter<<4;
	lcd_port &= 0x0F;
	lcd_port |= letter;
	sbit(lcd_port,RS);
	cbit(lcd_port,RW);
	sbit(lcd_port,EN);
	_delay_ms(5);
	cbit(lcd_port,EN);
}


//Function to bring cursor at home position
void LCD::home()
{
	writeCommand(0x80);
}


//Function to Print String on LCD
void LCD::print(char *str)
{
	while(*str != '\0')
	{
		writeChar(*str);
		str++;
	}
}

//Position the LCD cursor at "row", "column".

void LCD::cursor (char row, char col)
{
	
	switch (row) {
		case 1: writeCommand (0x80 + col - 1); break;
		case 2: writeCommand (0xc0 + col - 1); break;
		case 3: writeCommand (0x94 + col - 1); break;
		case 4: writeCommand (0xd4 + col - 1); break;
		default: break;
	}
	if(row==0&&col==0)home();
}


void LCD::print(unsigned long val,char row,char col)
{
	
	int i=0;
	for( i=0;val;i++)
	{
		temp=val%10;
		val=val/10;
		buffer[i]=temp+48;
	}
	cursor(row,col);
	
	i--;
	for(i=i;i>=0;i--)writeChar(buffer[i]);
	for( i=0;i<5;i++)writeChar(' ');
}