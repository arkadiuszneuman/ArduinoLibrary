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
#include "FadedLed.h"

class RobotMotor
{
 private:
	 //Led forwardPin, backwardPin;
	 BrightnessLed forwardPin, backwardPin;
	 bool isForward;
	 bool isStopped;
	 void SmoothStop(BrightnessLed& pin);
	 void SmoothStart(BrightnessLed& pin, byte speed);
	 byte GetSpeedFromPercent(byte percent);
public:
	 RobotMotor();
	 void MoveForward(byte percent = 100);
	 void MoveBackward(byte percent = 100);
	 void Stop();
};


#endif

