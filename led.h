// led.cpp.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ISwitchable.h"

class Led : public ISwitchable
{
 private:
	 int pin;
	 int state;
 public:
	 Led(int pin);
	 void On();
	 void Off();
	 int GetState();
	 void Loop();
};

#endif

