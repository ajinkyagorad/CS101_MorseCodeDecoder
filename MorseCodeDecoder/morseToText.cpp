/*
 * morseToText.cpp
 *
 * Created: 08-04-2015 10:56:00 PM
 *  
 */ 

#include "morseToText.h"

decoder::decoder()
{
	
}
/************************************************************************
*FUNCTION : decodeToLetter(char * morseSequence)
*INPUT	: pointer to character array holding the dit dah sequence 
			dit must be represented by ASCII value '1'           
			dah must be represented by ASCII value '3'
			non informative terminating character must be  other than ASCII '1' or '3'
*OUTPUT : character to respective input morse sequence         
*OPERATION WAY :
		   Using  morse code tree (http://upload.wikimedia.org/wikipedia/commons/c/ca/Morse_code_tree3.png)
		   in Array.
		   Initial positon at start ie 0 .
		   If dit branch to (2n+1)th position
		   If dah branch to (2n+2)th position
		   else return character equivalent of current positon 
			after checking if it was not space and 
			                                              
*************************************************************************/
char decoder::decodeToLetter( const char * morseSequence)
{
	int index=0,dataPos=0;
	for(int i=0;i<7;i++)
	{
		if(morseSequence[i]=='1')index=2*index+1;
		else 
		if(morseSequence[i]=='3')index=2*index+2;
		else											//end of morse sequence
		{
			return morseData[index];
		}
	}
	return ' ';				//if still in case not NICE morseSequence
	
}

