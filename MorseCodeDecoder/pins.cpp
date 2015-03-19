/*
 * pins.cpp
 *
 * Created: 07-03-2015 02:18:16 PM
 *  Author: Ajinkya
 */ 


#include "pins.h"

pin::pin()
{
	
}
pin::pin(int _pinNum)
{
	
	 portIndex=_pinNum/10;	//for A(0),B(1),C(2)
	 mask=_pinNum%10;
	 mask=(1<<mask);
	
	switch(portIndex)
	{
		case 0 : 
				port=&PORTA;
				ddr=&DDRA;
				pinState=&PINA;
			break;
		case 1 :
				port=&PORTB;
				ddr=&DDRB;
				pinState=&PINB;
			break;
		case 2 :
				port=&PORTC;
				ddr=&DDRC;
				pinState=&PINC;
			break;
		case 3 :
				port=&PORTD;
				ddr=&DDRD;
				pinState=&PIND;
			break;
		}
	output();
	
}
  void  pin::high()
{	
	*port|=mask;
}
 void  pin::low()
{
	*port&=(~mask);
}
 void  pin::output()
{
	*ddr|=mask;
}
 void  pin::input()
{
	*ddr&=(~mask);
}
 char  pin::read()
{
	return ((*pinState)&mask);
}
