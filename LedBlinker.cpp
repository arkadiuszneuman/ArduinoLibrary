// 
// 
// 

#include "LedBlinker.h"

LedBlinker::LedBlinker(int pin, int intervalOn, int intervalOff)
	: led(pin, 3)
{
	SetIntervals(intervalOn, intervalOff);
}

void LedBlinker::SetIntervals(int intervalOn, int intervalOff)
{
	this->intervalOn = intervalOn;
	this->intervalOff = intervalOff;

	if (led.GetState() == LOW)
	{
		timer.SetInterval(intervalOff);
	}
	else
	{
		timer.SetInterval(intervalOn);
	}
}

void LedBlinker::Loop()
{
	led.Loop();
	
	if (timer.TimePassed())
	{
		if (led.GetState() == LOW)
		{
			timer.SetInterval(intervalOn);
			led.LedOn();
		}
		else
		{
			timer.SetInterval(intervalOff);
			led.LedOff();
		}
	}
}
