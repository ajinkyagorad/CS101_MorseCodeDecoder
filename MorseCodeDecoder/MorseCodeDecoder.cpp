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
#include "uart0.h"
#include "Processor.h"
#include "morsebuzzer.h"
int main(void)
{
	LCD lcd;
	pulse code;
	uart0 serial(57600);
	Processor motor;
	morsebuzzer buzz;
	
	buzz.morseTransmit("Hello");
	lcd.print(":)");
	serial.printStr("Initialised\r\n");
	systime::sysTimeInit();
	char data[7]="";
	char buffer [20];
	
    while(1)
    {
		char  isValid;
         if(code.receiveCode()>0)
		 {
			  isValid=1;
		 }
		 else 
		 {
			 isValid=0;
		 }
		 
		  isValid=code.decodeToDitDah();
		 code.getDecodedData(data);
		 if(data[1]=='0')isValid=0;		//avoiding one units of transmit
		 if(isValid>0)
		 {
		 lcd.cursor(2,10);
		 lcd.print("Ok");
		 sprintf(buffer,"T:%lu",systime::getSysTime());
		 data[6]=0;
		 serial.printStr(data);
		 serial.printStr("\t");
		 serial.printStr(buffer);
		 serial.write(0x0d);
		 serial.write(0x0a);
		 lcd.home();
		 lcd.print(data);
		 lcd.cursor(2,1);
		 lcd.print(buffer);
		 }else{
			  lcd.cursor(2,10);
			  lcd.print("Er");
		 }
    }
}