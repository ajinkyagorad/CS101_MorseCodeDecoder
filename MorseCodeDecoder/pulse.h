/*
 * pulse.h
 *
 * Created: 12-03-2015 10:57:09 PM
 *  Author: Ajinkya
 aboutFile: 
	Header  file for pulse 
 */ 


#ifndef PULSE_H_
#define	PULSE_H_

#include "config.h"
#include "systime.h"
//pulseInfo holds start time and stop time in cpu counter clocks
struct pulseInfo{
	unsigned long startTime;	//start time in in cou counter clocks
	unsigned long stopTime;			//stop time in cpu counter clocks
	unsigned int numberOfEdges;		//number of falling edges in pulse
	unsigned int pulseWidthTime;	//pulse width in milliSeconds
	char ifData;					//checks on the validity of the data
	void setPulseWidthTime();
	
	
	};
class pulse
{
	pulseInfo pulseData;						//current information about current pulse
	pulseInfo morsePulses[6];					//array for storing information about consecutive morse pulses
	char DitDah[6];								//decoded sequence of dits and dahs
	char flag;
	bool isDitTimeout;									//flag for validity of data stored
	unsigned int timeout;						//timeout in milli second for receiving pulses
	unsigned int thresholdTime;		//setting minimum threshold time for noise removal
	unsigned int maxThresholdTime;	//setting maximum threshold time for noise removal
	unsigned int tDit,tDah;			//time for dits and dahs in ms
	unsigned int wordsPerMinute;	
	unsigned int tolerance;			//tolerance time for dit and dahs in ms
	bool errorCheck;
	public:
		pulse();
		~pulse();
		void init();
		bool decodeToDitDah();	//decode received sequence of data to dit-dah
		char receiveCode();
		void getDecodedData(char *buffer);
		
	private:
		char capture();						//capture pulse start & stop time in ms
		void delay(unsigned int time_ms);						//delay in ms
		unsigned int  absolute(int x);
	
	};


#endif /* INCFILE1_H_ */