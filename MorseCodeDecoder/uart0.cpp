/*
 * uart0.cpp
 *
 * Created: 30-03-2015 10:04:55 PM
 *  Author: Ajinkya
 */ 
#include "uart0.h"
/*
uart0 initialises UART0 given baud rate
*/
uart0::uart0(unsigned long _baud)
{
	DDRE|=1<<PE1;		//make tx pin output
	DDRE&= ~(1<<PE0);	//make rx pin input
	UBRR0=F_CPU/16/_baud -1;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);	//enable receiver and transmitter
	UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);	
	baud=_baud;				//save a copy of it
}
void uart0::write(unsigned char data)
{
	while( !(UCSR0A &(1<<UDRE0)));	//wait for emptying transmit buffer
	UDR0=data;	//write data
}

unsigned char uart0::read(void)
{
	while(!(UCSR0A & (1<<RXC0)));		//wait for data to be received
	return UDR0;
}

void uart0::printStr(const char * str)
{
	while(*str)
	{
		write(*str++);
	}
}