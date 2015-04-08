/*
 * Processor.cpp
 *
 * Created: 24-03-2015 22:49:02
 *  Author: Jenil
 */ 

// This is to process input from the Morse Code and act accordingly

#include "Processor.h"

int Processor::process(char decoded)
{
	decoded=toupper(decoded);
	if(decoded=='F')
	{
		moveMotorForward();
		return 0;
	}			
	if(decoded=='B')
	{
		moveMotorBackward();
		return 0;
	}			
	else
		return -1;		
}

void Processor::motionConfig()
{
	DDRA |=0x0F;		//Output
	PORTA &= 0x00;		//Initially stop
	DDRL |= 0x18;		// Enable pin.
	PORTL |= 0x18;
}

void Processor::motorStop()
{
	PORTA = 0x00;
}

void Processor::forward()
{
	PORTA = 0x06;
}

void Processor::backward()
{
	PORTA = 0x09;
}

void Processor::moveMotorForward()
{
	forward();
	_delay_ms(2000);
	motorStop();
	//_delay_ms(2000);
}

void Processor::moveMotorBackward()
{
	backward();
	_delay_ms(2000);
	motorStop();
	//_delay_ms(2000);
}
Processor::Processor()
{
	motionConfig();		//initialise the pins 
}