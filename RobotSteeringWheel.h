// RobotSteringWheel.h

#ifndef _ROBOTSTERINGWHEEL_h
#define _ROBOTSTERINGWHEEL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Mistumi95SP9PUnipolar.h"
#include "RobotLCD.h"

class RobotSteeringWheel
{
 private:
	 Mistumi95SP9PUnipolar stepper;
	 static const byte left = 3, right = 2, straight = 1;
	 static const float fullRotation = Mistumi95SP9PUnipolar::STEPS * 57 * 2;
	 byte direction;
 public:
	RobotSteeringWheel();
	void TurnLeft();
	void TurnRight();
	void TurnStaight();
};

#endif

