/*
 * systime.cpp
 *
 * Created: 19-03-2015 07:12:45 PM
 *  Author: Ajinkya
 */ 

#include "systime.h"

namespace systime{

//global variable in namespace systime for interrupt
unsigned long overflows=0;
//INTERRUPT EVENT HANDLER
//INPUT		: NONE
//OUTPUT	: NONE
//TIMER3 OVERFLOW INTERRUPT occurs every 4.55 Seconds
ISR(TIMER3_OVF_vect)	
{
	overflows++;
}

//FUNCTION  : getOverflows()
//INPUT		: NONE
//OUTPUT	: number of timer3 overflows

unsigned long getOverflows()		
{
	return overflows;	
}
//FUNCTION  :sysTimeInit()
//INPUT		: NONE
//OUTPUT	: NONE
//	Initialises the Timer3 with prescaler of 1024 sync to system clock
void sysTimeInit()
{
	
	cli();							//disable interrupts
	TCCR3A=0;
	TCCR3B=(1<<CS32)|(1<<CS30);		//use prescaler of 1024
									//counting clock is now F_OSC/1024
									//corresponding to 69.44 uS on 14.7456 MHz
	TCCR3C=0;
	TIMSK3=1<<TOIE3;				// Enable timer overflow interrupt
	overflows=0;
	TCNT3=0;						//clear timer3 counter value
	sei();							//Enable interrupts	
}
//FUNCTION  : getSysTime()
//INPUT		: NONE
//OUTPUT	: returns time in milli Seconds after initialisatin of sysTime
unsigned long getSysTime()		
{
	return (unsigned long)(getSysTimeRaw()*0.06944);
}
//FUNCTION  : getSysTimeRaw()
//INPUT		: NONE
//OUTPUT	: returns time ticks (raw counter values with overflows) after initialisation of sysTime
unsigned long getSysTimeRaw()			//returns the raw countervalue
{
	unsigned long temptime=TCNT3;					//get counter value at this state
	return overflows*65536+temptime;				
}

};