/*
 * pulse.cpp
 *
 * Created: 12-03-2015 10:57:14 PM
 *  Author: Ajinkya
 */ 
#include "pulse.h"
pulse::pulse()
{
	pulseData.ifData=0;		//set validity of data to invalid
	timeout=2;				//timeout in ms for getting pulse
	wordsPerMinute=15;		//WPM of morse code
	tDit=1200/wordsPerMinute;	//calculates time of dits given WPM		
	tDah=3*tDit;				//calculates time of dahs from tDit
	thresholdTime=tDit/2;		//used for removal of pulses of length less than it (in ms)	must be +ve assume tdit >20
	maxThresholdTime=(tDah*3)/2;	//used for removal of pulses of length more than it (in ms)	[threshold times doesn't account in errorCheck , removed in capture sequence]
	errorCheck=true;			//for calculating error checks on received pulse data
	tolerance=tDit;
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
/*********************************************************
*FUNCTION : pulse::capture()
*INPUT : NONE
*OUTPUT : validity of data  (flag)
			1 if valid data
			1 if pulse :ditTimeout bit is set
			0 if edge timeout
*!NOTE! : calling this function be sure about that pulse will arrive
*
*initialise timer1 in 16 bit counter mode with falling edge on T1 pin
*check every 2 ms that counter is incremented or not
*if incremented continue to check
*else exit loop and save timer value as pulse count 
*********************************************************/
char pulse::capture()
{
	init();					//initialise registers for capture
	pulseData.numberOfEdges	= 0;		
	unsigned long temptime=systime::getSysTime();										//save time when it looks for a pulse 
	while(TCNT1 == 0){
		if( (systime::getSysTime()-temptime)>(unsigned long)(1.5*tDit))					//check if sufficient time has passed after
		{
			isDitTimeout=true;															//if yes setDitTimeout Bit
			flag=1;
			return flag;
		}
	};		//wait for first falling edge		//ie within timeout edge is detected
	
	pulseData.startTime=systime::getSysTime();	//save START TIME
	isDitTimeout=false;
	while(true)									
	{
		pulseData.numberOfEdges=TCNT1;
		delay(timeout);								///timeout value pulse edge timeoutSS
		if(pulseData.numberOfEdges == TCNT1)break;	//break only if counter value
													//does not changes within timeout
	}
	pulseData.stopTime=systime::getSysTime();		//save pulse STOP TIME
	pulseData.setPulseWidthTime();					
	
	if((pulseData.pulseWidthTime<thresholdTime)	&&	(pulseData.pulseWidthTime>maxThresholdTime)	)//flag for error
	{
		flag=0;			//invalid flag : unsuccessful
	}else{
		flag=1;			//valid flag   : successful
	}
	pulseData.ifData=flag;			//says validity of pulse data
	return flag;
}
/***************************************
*char pulse::receiveCode()
*returns 1 if successful 
****************************************/
char pulse::receiveCode()	
{
	char timeoutNo=0;
	bool isFirstTimeout=true;
	for(int i=0; i<6; )
	{
		char isValid = capture();		//receive data for pulse
		if(isValid==1)				
		{
			if(isDitTimeout==false)		//c
			{
				morsePulses[i]=pulseData;		//if not ditTimeout then save the data and increment index 'i'
				morsePulses[i].ifData=1;
				i++;
			}else{								//else it was a ditTimeout
				
				if(isFirstTimeout==true)	//for first timout repeat and for other return it
				{
					isFirstTimeout = false;	//next time this  will not execute
					for(int j=5;j>i;j--)
					{
						morsePulses[j].ifData=0;				//make all other ifData zero
					}
					break;
				 }else{
					 			
					 continue;
						}
				}
		}else ;					//do nothing if it was not a valid data
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
/*********************************************
*bool pulse :: decodeToDitDah  
*extracts dit and dah from the morsePulses array and stores in  DitDah array
*returns true if successful (only if error checking) else false
*absense of errorChecking strictly calculates on based on (tDit+tDah)/2
**********************************************/
bool pulse::decodeToDitDah()
{
	
	//find number of morse pulses
	int i=0;
	for(i=0; i<6; i++) DitDah[i] = 0;		//make  all previous data to zero
	for( i=0;morsePulses[i].ifData!=0;i++);
	int numberOfPulses=i;
	for(int j=0;j<6;j++)
	{
		if(morsePulses[j].ifData==0)		//just to be safe
		{
			DitDah[j]=0;
			continue;
		}
		else{
				if(errorCheck)
				{
					if(j>0)			//if not the first pulse
					{
					unsigned long timeWidth (morsePulses[j].startTime-morsePulses[j-1].stopTime) ;		//finding time distance betn next pulse falling and previous pulse rising
					if(!((timeWidth>tDit/2) && ( timeWidth <tDah/2) ))return false;
					}
				}
				if( absolute(morsePulses[j].pulseWidthTime - tDah )<tolerance )							//its a dah
				{
					DitDah[j]=3;
				}
				else if(absolute(morsePulses[j].pulseWidthTime-tDit)<tolerance)							//its a dit
				{
					DitDah[j]=1;
				}else{
					return false;
				}
			}
	}
	return true;
}
/************************************************************************/
/* void pulse::getDecodedData(char *buffer)
/* input : pointer to a  buffer for storing decoded output              */
/************************************************************************/
void pulse::getDecodedData(char *buffer)
{
	for(int i=0;i<6;i++)buffer[i]=DitDah[i]+0x30;
}
/*********************************
*unsigned int pulse::absolute(int x)
*return absolute value of an integer
*********************************/
unsigned int pulse::absolute(int x)
{
	return (  (x>=0)?x:(-1)*x   );
}