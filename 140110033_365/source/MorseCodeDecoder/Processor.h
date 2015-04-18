/*
 * Processor.h
 *
 * Created: 24-03-2015 22:46:33
 *  Author: Jenil
 */ 


#ifndef PROCESSOR_H_
#define PROCESSOR_H_
#include "config.h"
#include "motor.h"

#include <ctype.h>		//for converting to uppercase
class Processor:public movement
{
	movement motor;
	public:
		char process(char decoded);
		Processor();
	
	
		
		
	
};

#endif /* PROCESSOR_H_ */