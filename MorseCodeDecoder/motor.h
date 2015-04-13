/*
 * motor.h
 *
 * Created: 09-04-2015 04:27:02 PM
 * 
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "config.h"
//using feedback system to move at specific angles

class movement{
		void motionPinConfig (void);
		void leftEncoderPinConfig (void);
		void rightEncoderPinConfig (void);
		void portInit();
		void leftPositionEncoderInterruptInit (void);
		void rightPositionEncoderInterruptInit (void);
		void motionSet (unsigned char Direction);
	public	:
		movement();
		void init();
		void forward (void);
		void back (void);
		void left (void);
		void right (void);
		void softLeft (void);
		void softRight (void);
		void softLeftBack (void);
		void softRightBack (void);
		void stop (void);
		void angleRotate(unsigned int Degrees);
		void distance(unsigned int DistanceInMM);
		void forward(unsigned int DistanceInMM);
		void back(unsigned int DistanceInMM);
		void left(unsigned int Degrees);
		void right(unsigned int Degrees);
		void softLeft(unsigned int Degrees);
		void softRight(unsigned int Degrees);
		void softLeftBack(unsigned int Degrees);
		void softRightBack(unsigned int Degrees);
	};


#endif /* MOTOR_H_ */