/*
 * motor.cpp
 *
 * Created: 09-04-2015 04:27:17 PM
 *  
 */ 
#include "motor.h"
//---------------------------------------------------
//ISR for right position encoder
namespace movementISR{

		volatile unsigned long int ShaftCountLeft = 0; //to keep track of left position encoder
		volatile unsigned long int ShaftCountRight = 0; //to keep track of right position encoder
		volatile unsigned int Degrees; //to accept angle in degrees for turning
	
	ISR(INT5_vect)
	{
		ShaftCountRight++;  //increment right shaft position count
	}


	//ISR for left position encoder
	ISR(INT4_vect)
	{
		ShaftCountLeft++;  //increment left shaft position count
	}

}
//-----------------------------------------------
movement::movement()
{
	
}
//Function to configure ports to enable robot's motion
void movement::motionPinConfig (void)
{
	DDRA = DDRA | 0x0F;
	PORTA = PORTA & 0xF0;
	DDRL = DDRL | 0x18;   //Setting PL3 and PL4 pins as output for PWM generation
	PORTL = PORTL | 0x18; //PL3 and PL4 pins are for velocity control using PWM.
}

//Function to configure INT4 (PORTE 4) pin as input for the left position encoder
void movement::leftEncoderPinConfig (void)
{
	DDRE  = DDRE & 0xEF;  //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x10; //Enable internal pull-up for PORTE 4 pin
}

//Function to configure INT5 (PORTE 5) pin as input for the right position encoder
void movement::rightEncoderPinConfig (void)
{
	DDRE  = DDRE & 0xDF;  //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x20; //Enable internal pull-up for PORTE 4 pin
}

//Function to initialize ports
void movement::portInit()
{
	motionPinConfig(); //robot motion pins config
	leftEncoderPinConfig(); //left encoder pin config
	rightEncoderPinConfig(); //right encoder pin config
}

void movement::leftPositionEncoderInterruptInit (void) //Interrupt 4 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x02; // INT4 is set to trigger with falling edge
	EIMSK = EIMSK | 0x10; // Enable Interrupt INT4 for left position encoder
	sei();   // Enables the global interrupt
}

void movement::rightPositionEncoderInterruptInit (void) //Interrupt 5 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x08; // INT5 is set to trigger with falling edge
	EIMSK = EIMSK | 0x20; // Enable Interrupt INT5 for right position encoder
	sei();   // Enables the global interrupt
}



//Function used for setting motor's direction
void movement::motionSet (unsigned char Direction)
{
	unsigned char PortARestore = 0;

	Direction &= 0x0F; 		// removing upper nibbel for the protection
	PortARestore = PORTA; 		// reading the PORTA original status
	PortARestore &= 0xF0; 		// making lower direction nibbel to 0
	PortARestore |= Direction; // adding lower nibbel for forward command and restoring the PORTA status
	PORTA = PortARestore; 		// executing the command
}

void movement::forward (void) //both wheels forward
{
	motionSet(0x06);
}

void movement::back (void) //both wheels backward
{
	motionSet(0x09);
}

void movement::left (void) //Left wheel backward, Right wheel forward
{
	motionSet(0x05);
}

void movement::right (void) //Left wheel forward, Right wheel backward
{
	motionSet(0x0A);
}

void movement::softLeft (void) //Left wheel stationary, Right wheel forward
{
	motionSet(0x04);
}

void movement::softRight (void) //Left wheel forward, Right wheel is stationary
{
	motionSet(0x02);
}

void movement::softLeftBack (void) //Left wheel backward, right wheel stationary
{
	motionSet(0x01);
}

void movement::softRightBack (void) //Left wheel stationary, Right wheel backward
{
	motionSet(0x08);
}

void movement::stop (void)
{
	motionSet(0x00);
}


//Function used for turning robot by specified degrees

void movement::angleRotate(unsigned int Degrees)
{
	float ReqdShaftCount = 0;
	unsigned long int ReqdShaftCountInt = 0;
	using namespace movementISR;
	ReqdShaftCount = (float) Degrees/ 4.090; // division by resolution to get shaft count
	ReqdShaftCountInt = (unsigned int) ReqdShaftCount;
	ShaftCountRight = 0;
	ShaftCountLeft = 0;

	while (1)
	{
		if((ShaftCountRight >= ReqdShaftCountInt) | (ShaftCountLeft >= ReqdShaftCountInt))
		break;
	}
	stop(); //Stop robot
}


//Function used for moving robot forward by specified distance

void movement::distance(unsigned int DistanceInMM)
{
	float ReqdShaftCount = 0;
	unsigned long int ReqdShaftCountInt = 0;
	using namespace movementISR;
	ReqdShaftCount = DistanceInMM / 5.338; // division by resolution to get shaft count
	ReqdShaftCountInt = (unsigned long int) ReqdShaftCount;
	
	ShaftCountRight = 0;
	while(1)
	{
		if(ShaftCountRight > ReqdShaftCountInt)
		{
			break;
		}
	}
	stop(); //Stop robot
}

void movement::forward(unsigned int DistanceInMM)
{
	forward();
	distance(DistanceInMM);
}

void movement::back(unsigned int DistanceInMM)
{
	back();
	distance(DistanceInMM);
}

void movement::left(unsigned int Degrees)
{
	// 88 pulses for 360 degrees rotation 4.090 degrees per count
	left(); //Turn left
	angleRotate(Degrees);
}



void movement::right(unsigned int Degrees)
{
	// 88 pulses for 360 degrees rotation 4.090 degrees per count
	right(); //Turn right
	angleRotate(Degrees);
}


void movement::softLeft(unsigned int Degrees)
{
	// 176 pulses for 360 degrees rotation 2.045 degrees per count
	softLeft(); //Turn soft left
	Degrees=Degrees*2;
	angleRotate(Degrees);
}

void movement::softRight(unsigned int Degrees)
{
	// 176 pulses for 360 degrees rotation 2.045 degrees per count
	softRight();  //Turn soft right
	Degrees=Degrees*2;
	angleRotate(Degrees);
}

void movement::softLeftBack(unsigned int Degrees)
{
	// 176 pulses for 360 degrees rotation 2.045 degrees per count
	softLeftBack(); //Turn reverse soft left
	Degrees=Degrees*2;
	angleRotate(Degrees);
}

void movement::softRightBack(unsigned int Degrees)
{
	// 176 pulses for 360 degrees rotation 2.045 degrees per count
	softRightBack();  //Turn reverse soft right
	Degrees=Degrees*2;
	angleRotate(Degrees);
}

//Function to initialize all the devices
void movement::init()
{
	cli(); //Clears the global interrupt
	portInit();  //Initializes all the ports
	leftPositionEncoderInterruptInit();
	rightPositionEncoderInterruptInit();
	sei();   // Enables the global interrupt
}

