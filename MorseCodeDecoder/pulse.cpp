/*
 * CPPFile1.cpp
 *
 * Created: 12-03-2015 10:57:14 PM
 *  Author: Ajinkya
 */ 
#include "pulse.h"
pulse::pulse()
{
	pulseData.ifData=0;
	
}
//pulse::init initialses the registers for counting the clock pulses on 
//T1 pin of mcu, 
void pulse::init(void)
{
	
	TCCR1A=0;		//not using any other mode
	TCCR1B=(1<<CS12)|(1<<CS10); //set clock prescaler as clkIO/1024
								//this corresponds to  clock tick time of 1024/FOSC (~ 69.45 uS)
	TCNT1=0;					//set initial value of counter to zero
	OCR1A=0;					//not using other timer modules
	OCR1B=0;
	ICR1=0;
	TIMSK1=0;					//not using interrupts for timer 1
	TIFR1=0;
	sei();
}

//FUNCTION : pulse::capture()
//ARGUMENTS : NONE
//RETURN : validity of data  (flag)
//!NOTE! : calling this function be sure about that pulse will arrive
//initialise timer1 in 16 bit counter mode with falling edge on T1 pin
//check every 2 ms that counter is incremented or not
//if incremented continue to check
//else exit loop and return timer value
char pulse::capture()
{
	
}