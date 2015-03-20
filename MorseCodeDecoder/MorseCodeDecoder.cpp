/*
 * MorseCodeDecoder.cpp
 *
 * Created: 12-03-2015 09:36:47 PM
 */ 
//
//Program for Firebird V : Morse Code Decoder

#define F_CPU 14745600	//Xtal Frequency
#include "config.h"
#include "pins.h"
#include "pulse.h"
#include "systime.h"
#include "lcd.h"
int main(void)
{
	LCD lcd;
	pulse code;
	lcd.print(":)");
	systime::sysTimeInit();
	char data[7]="EEEEEE";	
	char buffer [20];
	DDRJ=0xAA;
    while(1)
    {
         while(!code.receiveCode())		//wait while receiving the code
		 {
			 PORTJ=0XFF;
			 PORTJ=0X00;
		 }
		 code.decodeToDitDah();
		 code.getDecodedData(data);
		 sprintf(buffer,"T:%lu",systime::getSysTime());
		 data[6]=0;
		 lcd.home();
		 lcd.print(data);
		 lcd.cursor(2,1);
		 lcd.print(buffer);
    }
}