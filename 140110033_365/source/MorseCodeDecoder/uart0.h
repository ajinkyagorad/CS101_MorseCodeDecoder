/*
 * uart0.h
 *
 * Created: 30-03-2015 10:04:43 PM
 *  Author: Ajinkya
 */ 
/*
Asynchronous Normalmode (U2Xn = 0) Baud=fosc/16/(UBRRn+1)

		UBRRn=(fosc/16/BAUD) -1
*/
#ifndef UART0_H_
#define UART0_H_
#include "config.h"
//currently no parity, 8bit ,one stop bit
class uart0 {
	unsigned long baud;
	public:
		uart0(unsigned long _baud=9600);
		void write(unsigned char data);
		unsigned char read(void );
		void printStr(const char * str);
	};



#endif /* UART0_H_ */