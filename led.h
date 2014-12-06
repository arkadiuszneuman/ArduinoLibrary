// led.cpp.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Led
{
 private:
	 int pin;
	 int state;
 public:
	 Led(int pin);
	 void LedOn();
	 void LedOff();
	 int GetState();
};

#endif

