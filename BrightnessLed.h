// FadeLed.h

#ifndef _BRIGHTNESSLED_h
#define _BRIGHTNESSLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class BrightnessLed
{
private:
	int pin;
	byte brightness;
public:
	BrightnessLed(int pin);
	void SetBrightness(byte brightness);
	byte GetBrightness();
};


#endif

