/*
 * morseToText.h
 *
 * Created: 08-04-2015 10:56:18 PM
 *  
 */ 


#ifndef MORSETOTEXT_H_
#define MORSETOTEXT_H_
//to store data in tree structure 
//nextDit,nextDah corresponds to pointer to the next branch of dit ,dah respectively
// data holds the morse code decoded sequence at that position

class decoder{
		const int numberOfNodes=63;			//Number of nodes =2^n+1-1 where n is number of levels (including master(topmost) node
		const char morseData[63]={					
																				' '	,
										'E',																		'T',
						'I',								'A',								'N',							'M',
		       'S',             'U',               'R',              'W',             'D',              'K',              'G',             'O',
		  'H',     'V',     'F',     'U',     'L',     'A',     'P',     'J',     'B',     'X',     'C',     'Y',     'Z',     'Q',     ' ',    ' ',
		'5','4', ' ','3', ' ',' ', ' ',' ', '2',' ', ' ','+', ' ',' ', ' ','1',	'6','=', '/',' ', ' ',' ', ' ',' ', '7',' ', ' ',' ', '8',' ', '9','0',
										
		};			//space ' ' represents no data not required character => invalid data
		
	public:
		decoder();
		char decodeToLetter(const char *  morseSequence);
	};


#endif /* MORSETOTEXT_H_ */