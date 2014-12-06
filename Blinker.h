#ifndef _LEDBLINKER_h
#define _LEDBLINKER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "led.h"
#include "Timer.h"
#include "FadedLed.h"
#include "ISwitchable.h"

class Blinker
{
 private:
	 int intervalOn;
	 int intervalOff;

	 ISwitchable *switchable;
	 Timer timer;
 public:
	 Blinker(ISwitchable* switchable, int intervalOn, int intervalOff);
	 ~Blinker();
	 void SetIntervals(int intervalOn, int intervalOff);
	 void Loop();
};

#endif

