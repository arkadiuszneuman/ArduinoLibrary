// RobotMotor.h

#ifndef _ROBOTMOTOR_h
#define _ROBOTMOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Led.h"
#include "RobotLCD.h"

class RobotMotor
{
 private:
	 Led forwardPin, backwardPin;
	 bool isForward;
	 bool isStopped;
 public:
	 RobotMotor();
	 void MoveForward();
	 void MoveBackward();
	 void Stop();
};


#endif

