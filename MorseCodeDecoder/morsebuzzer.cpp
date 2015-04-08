
/*
 *	morsebuzzer.cpp
 *	Transmits morse buzzer output on PORTC.PC4
 *	Firebird has its buzzer connected to PORTC.PC4
 *
 *  Author: Kewal Bhat
 */ 
#include "morsebuzzer.h"
//delay timings:
//between two consecutive morse pulses : dit time
//between two consecutive letters : 3*dit time
//between two consecutive words	: 7*dit time

morsebuzzer::morsebuzzer (int t)
{
	timeofdit=t;
	buzzerPinConfig();
}
void morsebuzzer::buzzerPinConfig()
{
	DDRC|=0x08;
	PORTC&=~0x08;		//set it initially low
}


void morsebuzzer::morseTransmit(char data)
{
	char str1[7];
    int j=0;
	
		
		switch(toupper(data))
		{
			  case ' ':					//if space ie , 7 dits buzzer=>low
			  buzzerOff();
			  delay(timeofdit*7);
			  return;					//return for end of transmission
			  case 'A':
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case 'B':
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case 'C':
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j]='1';
			  break;
			  
			  case 'D':
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case 'E':
			  str1[j]='1';
			  break;
			  
			  case 'F':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j]='1';
			  break;
			  
			  case 'G':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j]='1';
			  break;
			  
			  case 'H':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case 'I':
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case 'J':
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case 'K':
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case 'L':
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case 'M':
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case 'N':
			  str1[j++]='3';
			  str1[j]='1';
			  break;
			  
			  case 'O':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case 'P':
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j]='1';
			  break;
			  
			  case 'Q':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case 'R':
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j]='1';
			  break;
			  
			  case 'S':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case 'T':
			  str1[j]='3';
			  break;
			  
			  case 'U':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case 'V':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case 'W':
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case 'X':
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case 'y':
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case 'Z':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case '0':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case '1':
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case '2':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j+1]='3';
			  str1[j]='3';
			  break;
			  
			  case '3':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  
			  case '4':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case '5':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case '6':
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case '7':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case '8':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case '9':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j]='1';
			  break;
			  
			  case '.':
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='3';
			  break;
			  
			  case ',':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j]='3';
			  break;
			  
			  case ':':
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  case '?':
			  str1[j++]='1';
			  str1[j++]='1';
			  str1[j++]='3';
			  str1[j++]='3';
			  str1[j++]='1';
			  str1[j]='1';
			  break;
			  
			  default:
			  break;
		}
	    j++;
	
	str1[j]='\0';
	for(int i=0;i<j;i++)
	{
		if(str1[i]=='1')
		{
		transmitDit();	
		}
		else if(str1[i]=='3')
		{
		transmitDah();
		}
		else continue;
	}
	delay(2*timeofdit);			//end of transmission
	//receive data and Xmit it's respective morse code on given ditTime on buzzer
	//example : if given character is 'W'
	//then code executed will be
	/*
	transmitDit();
	transmitDah();
	transmitDah();
	delay(2*timeofdit);			//2*tDit because one dit time delay occured in transmit sequence =>>total 3*tDit between letters
	
	*/
}
void morsebuzzer::morseTransmit( char* str)
{
	while(*str)
	{
		morseTransmit((char)(*str));
		str++;
	}
}

void morsebuzzer::morseTransmit(const char * str)
{
	morseTransmit((char*)str);
}
void morsebuzzer::transmitDit()
{
	buzzerOn();
	delay(timeofdit);
	buzzerOff();
	delay(timeofdit);
	
}
void morsebuzzer::transmitDah()
{
		buzzerOn();
		delay(3*timeofdit);
		buzzerOff();
		delay(timeofdit);
}
void morsebuzzer::buzzerOn()
{
	PORTC|=0x08;		//set buzzer on 
}
void morsebuzzer::buzzerOff()
{
	PORTC&=~0x08;	//set buzzer off
}
void morsebuzzer::delay(int time_ms)
{
	while(time_ms--)
	_delay_ms(1);
}
