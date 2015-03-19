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
	TCCR1B=(1<<CS12)|(1<<CS11); //set clock source as falling edge on T1 pin
	TCNT1=0;					//set initial value of counter to zero
	OCR1A=0;					//not using other timer modules
	OCR1B=0;
	ICR1=0;
	TIMSK1=0;					//not using interrupts for timer 1
	TIFR1=0;
	DDRD&=~(1<<PD6);							//make T1 pin as input PD6
}

//FUNCTION : pulse::capture()
//INPUT : NONE
//OUTPUT : validity of data  (flag)
//!NOTE! : calling this function be sure about that pulse will arrive
//
//initialise timer1 in 16 bit counter mode with falling edge on T1 pin
//check every 2 ms that counter is incremented or not
//if incremented continue to check
//else exit loop and save timer value as pulse count 
char pulse::capture()
{
	init();
	pulseData.numberOfEdges	= 0;		
	
	while(TCNT1 == 0);		//wait for first falling edge
	pulseData.startTime=systime::getSysTime();	//save start time 
	while(true)									
	{
		pulseData.numberOfEdges=TCNT1;
		_delay_ms(timeout);
		if(pulseData.numberOfEdges == TCNT1)break;	//break only if counter value
													//does not changes within timout
	}
	pulseData.stopTime=systime::getSysTime();		//save pulse stop time
	pulseData.setPulseWidthTime();					
	
	if(pulseData.pulseWidthTime<thresholdTime)
	{
		flag=0;			//invalid flag : unsuccessful
	}else{
		flag=1;			//valid flag   : successful
	}
	return flag;
}

void pulseInfo::setPulseWidthTime()
{
	pulseWidthTime=stopTime-startTime;
}