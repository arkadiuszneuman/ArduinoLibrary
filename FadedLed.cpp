// 
// 
// 

#include "FadedLed.h"

FadedLed::FadedLed(int pin, int fadeAmount)
	: brightnessLed(pin)
{
	this->state = LOW;
	this->brightness = 0;
	this->fadeAmount = fadeAmount;
}

void FadedLed::On()
{
	state = HIGH;
	timer.SetInterval(30);
}

void FadedLed::Off()
{
	state = LOW;
	timer.SetInterval(30);
}

void FadedLed::Loop()
{
	if (timer.TimePassed())
	{
		if (state == LOW)
		{
			brightness -= fadeAmount;
			if (brightness < 0)
			{
				brightness = 0;
				timer.Stop();
			}
		}
		else
		{
			brightness += fadeAmount;
			if (brightness > 255)
			{
				brightness = 255;
				timer.Stop();
			}
		}

		brightnessLed.SetBrightness(brightness);
	}
}

int FadedLed::GetState()
{
	return state;
}

