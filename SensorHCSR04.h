// SensorHCSR04.h

#ifndef _SENSORHCSR04_h
#define _SENSORHCSR04_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class SensorHCSR04
{
 private:
	 int triggerPin;
	 int echoPin;


 public:
	 SensorHCSR04(int triggerPin, int echoPin);
	 int GetCmDistance();
	 int GetOneMeasure();
};

#endif

