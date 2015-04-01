/*
 * pins.h
 *
 * Created: 07-03-2015 02:15:00 PM
 *  Author: Ajinkya
 */ 


#ifndef PINS_H_
#define PINS_H_
#include "avr/io.h"
class pin{
	
	char portIndex,mask;
	volatile uint8_t *port,*ddr,*pinState;
	public:
		pin();
		pin(int _pinNum);
		 void   high();
		 void  low();
		 void  output();
		 void  input();
		 char  read();
		 
	};



#endif /* PINS_H_ */