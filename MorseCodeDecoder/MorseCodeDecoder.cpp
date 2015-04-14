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

#include "Processor.h"
#include "morsebuzzer.h"
#include "morseToText.h"
int main(void)
{
	LCD lcd;
	pulse code;
	
	decoder decodeIt;
	Processor motor;
	morsebuzzer buzz;
	systime::sysTimeInit();
	buzz.morseTransmit("Hello");
	lcd.print(":)");
	

	char data[7]="";		//morse data to be stored in this array
	
	
    while(1)		//infinite loop
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
		 
		 isValid*=code.decodeToDitDah();
		 code.getDecodedData(data);		
		 if(data[1]=='0')isValid=0;		//avoiding one units of receive this will disable E(.) & T(-) of morse code 
		 if(isValid>0)				//if all valid data
		 {
		 lcd.cursor(2,10);
		 lcd.print("Ok");
		 
		 
		 data[6]=0;		//to make data a null terminated string
		 char letter=decodeIt.decodeToLetter(data);		//has data decoded to respective word
		 
		 lcd.cursor(1,10);
		 lcd.print(letter);
		 if(motor.process(letter))
		 {
			 buzz.sendRoger();
			 lcd.print("ROGER   ",2,0);
			 _delay_ms(500);
		 }
		 }else{
			 lcd.print("ERROR Rx",2,0);
		 }
    }
}