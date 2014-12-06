// LedBlinker.h

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

class LedBlinker
{
 private:
	 int intervalOn;
	 int intervalOff;

	 FadedLed led;
	 Timer timer;
 public:
	 LedBlinker(int pin, int intervalOn, int intervalOff);
	 void SetIntervals(int intervalOn, int intervalOff);
	 void Loop();
};

#endif

