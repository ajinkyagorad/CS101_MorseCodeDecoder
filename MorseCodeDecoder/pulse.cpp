/*
 * CPPFile1.cpp
 *
 * Created: 12-03-2015 10:57:14 PM
 *  Author: Ajinkya
 */ 
#include "pulse.h"
pulse::pulse()
{
	pulseData.ifData=0;		//set validity of data to invalid
	timeout=2;
	thresholdTime=20;
	wordsPerMinute=10;
	tDit=1200/wordsPerMinute;
	tDah=3*tDit;
	errorCheck=false;
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
	//need to add time out checking
	unsigned long temptime=systime::getSysTime();
	while(TCNT1 == 0){
		if( (systime::getSysTime()-temptime)>(unsigned long)(1.5*tDit)) 
		{
			isDitTimeout=true;
			flag=0;
			return flag;
		}
	};		//wait for first falling edge	
	
	pulseData.startTime=systime::getSysTime();	//save start time 
	isDitTimeout=false;
	while(true)									
	{
		pulseData.numberOfEdges=TCNT1;
		delay(timeout);
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
	pulseData.ifData=flag;			//say validity of pulse data
	return flag;
}

char pulse::receiveCode()
{
	char timeoutNo=0;
	for(int i=0;i<6;)
	{
		char isValid = capture();
		if(isDitTimeout==false)
		{
			
			morsePulses[i]=pulseData;
			i++;
		}else{
			timeoutNo++;
			if(timeoutNo!=1)	//for first timout repeat and for other return it
			{
				for(int j=5;j>i;j--)
				{
					morsePulses[5-i].ifData=0;				//make all other ifData zero
				}
				break;
			}else{
				 return 0;
				 }
				
		}
	
	}
	return 1;
}
void pulse::delay(unsigned int time_ms)
{
	while(time_ms--)_delay_ms(1);
}

void pulseInfo::setPulseWidthTime()
{
	pulseWidthTime=stopTime-startTime;
}

bool pulse::decodeToDitDah()
{
	
	//find number of morse pulses
	int i=0;
	for( i=0;morsePulses[i].ifData!=0;i++);
	int numberOfPulses=i;
	for(int j=0;j<numberOfPulses;j++)
	{
		if(morsePulses[i].ifData==0)		//just to be safe
		{
			DitDah[i]=0;
			continue;
		}
		if(errorCheck)
		{
			if(j>0)			//if not the first pulse
			{
			unsigned long timeWidth (morsePulses[i].startTime-morsePulses[i-1].stopTime) ;
			if(!((timeWidth>tDit/2) && ( timeWidth <tDah/2) ))return false;
			}
		}
		if(morsePulses[i].pulseWidthTime > ((tDit+tDah)/2 ) )	//its a dah
		{
			DitDah[i]=3;
		}
		else													//its a dit
		{
			DitDah[i]=1;
		}
	}
	return true;
}
void pulse::getDecodedData(char *buffer)
{
	for(int i=0;i<6;i++)buffer[i]=DitDah[i]+0x30;
}