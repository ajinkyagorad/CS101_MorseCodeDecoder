
/*
 * morsebuzzer.cpp
 *
 *  Author: Kewal Bhat
 */ 
#include "morsebuzzer.h"


morsebuzzer::morsebuzzer (int t)
{
	timeofdit=t;
	buzzerPinConfig();
}
void morsebuzzer::buzzerPinConfig()
{
	DDRC|=0x08;
	PORTC&=~0x08;
}


void morsebuzzer::morseTransmit(char data)
{
	char str1[7];
    int j=0;
	
		
		switch(toupper(data))
		{
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
		
		}
	    j++;
	
	str1[j-1]='\0';
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
	}
	//receive data and Xmit it's respective morse code on given ditTime on buzzer
	//example : if given character is 'W'
	//then code executed will be
	/*
	transmitDit();
	transmitDah();
	transmitDah();
	delay(2*timeofdit);
	
	*/
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
	DDRC|=0x08;		//set buzzer on 
}
void morsebuzzer::buzzerOff()
{
	DDRC&=~0x08;	//set buzzer off
}
void morsebuzzer::delay(int time_ms)
{
	while(time_ms)
	_delay_ms(1);
}
