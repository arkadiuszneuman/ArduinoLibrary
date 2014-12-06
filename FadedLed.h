// FadedLed.h

#ifndef _FADEDLED_h
#define _FADEDLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BrightnessLed.h"
#include "Timer.h"
#include "ISwitchable.h"

class FadedLed : public ISwitchable
{
private:
	BrightnessLed brightnessLed;
	Timer timer;
	int state;
	int brightness;
	int fadeAmount;
public:
	FadedLed(int pin, int fadeAmount = 5);
	void On();
	void Off();
	void Loop();
	int GetState();
};


#endif

