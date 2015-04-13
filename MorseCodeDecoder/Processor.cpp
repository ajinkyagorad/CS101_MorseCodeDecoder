/*
 * Processor.cpp
 *
 * Created: 24-03-2015 22:49:02
 *  Author: Jenil
 */ 

// This is to process input from the Morse Code and act accordingly

#include "Processor.h"

char Processor::process(char decoded)
{
	
	decoded=toupper(decoded);
	switch(decoded)	
	{
		case 'F' :
			forward(500);
			break;
		case 'B' : 
			back(500);
			break;
		case 'R' :
			right(90);
			break;
		case 'L' :
			left(90);
			break;
		
		default :
			if(decoded >='3' && decoded<='9')
			{
				int sides=decoded-'0';
				int angle =360/sides;
				
				for(int i=0;i<sides;i++)
				{
					forward(400);
					angleRotate(angle);
				}
			}
			else
			{
					return 0;			//error
			}
	}
	return 1;		//say it was successful
}


Processor::Processor()
{
	motor.init();
	
}
