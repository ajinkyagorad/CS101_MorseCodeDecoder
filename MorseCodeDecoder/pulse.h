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
//pulseInfo holds start time and stop time in cpu counter clocks
struct pulseInfo{
	unsigned long startTime;	//start time in in cou counter clocks
	unsigned long stopTime;			//stop time in cpu counter clocks
	unsigned int numberOfEdges;		//number of falling edges in pulse
	unsigned int pulseWidthTime;	//pulse width in milliSeconds
	char ifData;					//checks on the validity of the data
	};
class pulse
{
	pulseInfo pulseData;
	char flag;
	
	public:
		pulse();
		~pulse();
		void init();
		char capture();						//capture pulse start & stop time in ms
		char* decodeToDitDah(pulseInfo * );	//decode received sequence of data to dit-dah
		
		
		
	
	};


#endif /* INCFILE1_H_ */