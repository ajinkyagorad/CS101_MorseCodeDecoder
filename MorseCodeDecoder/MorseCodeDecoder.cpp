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
	char data[7];
    while(1)
    {
         while(!code.receiveCode());		//wait while receiving the code
		 code.decodeToDitDah();
		 code.getDecodedData(data);
		 data[6]=0;
		 lcd.home();
		 lcd.print(data);
    }
}