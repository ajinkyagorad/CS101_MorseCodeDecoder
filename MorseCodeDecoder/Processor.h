/*
 * Processor.h
 *
 * Created: 24-03-2015 22:46:33
 *  Author: Jenil
 */ 


#ifndef PROCESSOR_H_
#define PROCESSOR_H_
#include "config.h"

class Processor
{
	public:
		void process(char decoded);
	protected:
	private:
		void motionConfig();
		void motorStop();
		void forward();
		void backward();
		void moveMotorForward();
		void moveMotorBackward();	
};

#endif /* PROCESSOR_H_ */