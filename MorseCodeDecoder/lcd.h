/*
 * lcd.h
 *
 * Created: 07-03-2015 05:53:01 PM
 *  Author: Ajinkya
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "config.h"


#define RS 0
#define RW 1
#define EN 2
#define lcd_port PORTC

#define sbit(reg,bit)	reg |= (1<<bit)			// Macro defined for Setting a bit of any register.
#define cbit(reg,bit)	reg &= ~(1<<bit)		// Macro defined for Clearing a bit of any register.
class LCD{
	unsigned long temp;
	char  buffer[20];

	public: 
	LCD();
	void portConfig(void);
	//void lcd_reset();
	void home();
	void portInit();
	void set4bit();
	void init();
	void writeCommand(unsigned char);
	void writeChar(char );
	void print(char*);
	void print(const char * );
	void cursor(char,char);
	void print(unsigned long val,char row,char col);
	
	
	

	};






#endif /* LCD_H_ */