/*
 * IncFile1.h
 *
 * Created: 12-03-2015 10:57:09 PM
 *  Author: Ajinkya
 aboutFile: 
	Header  file for pulse 
 */ 


#ifndef PULSE_H_
#define	PULSE_H_

#include "config.h"
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
	pulseInfo morsePulses[6];					//array for 
	char flag;									//flag for validity of data stored
	const int timeout=2;						//timeout in milli second for receiving pulses
	unsigned int thresholdTime=20;		//setting threshold time for noise removal
	public:
		pulse();
		~pulse();
		void init();
		char* decodeToDitDah(pulseInfo * );	//decode received sequence of data to dit-dah
		char receiveCode()
	private:
		char capture();						//capture pulse start & stop time in ms
	
	};


#endif /* INCFILE1_H_ */