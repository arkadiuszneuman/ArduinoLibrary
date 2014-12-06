// Timer.h

#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Timer
{
 private:
	 unsigned long interval;
	 unsigned long previousMillis;
	 bool isStarted;
 public:
	 Timer(unsigned long interval = 0);
	 void SetInterval(unsigned long interval);
	 void Reset();
	 void Start();
	 void Stop();
	 bool TimePassed();
	 bool IsStarted();
};



#endif

