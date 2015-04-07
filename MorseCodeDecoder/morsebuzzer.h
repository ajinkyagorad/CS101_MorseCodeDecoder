

/*
 * morsebuzzer.cpp
 *
 *  Author: Kewal Bhat
 */ 

#ifndef MORSEBUZZER_H_
#define MORSEBUZZER_H_

#include "config.h"
#include <ctype.h>			//for toupper
class morsebuzzer {
		int timeofdit;
		
		void buzzerOn();
		void buzzerOff();
		void buzzerPinConfig();
		void transmitDit();
		void transmitDah();
		void delay(int time_ms);
	public:
		morsebuzzer(int t=40);		//set default time to 40 ms giving WPM of 1200/40=30
		void morseTransmit(char data);
		
		

};

#endif 