#include "FadedLed.h"

FadedLed::FadedLed(int pin, int fadeAmount)
	: brightnessLed(pin)
{
	this->state = LOW;
	this->brightness = 0;
	this->fadeAmount = fadeAmount;
	this->maxBrightness = 255;
}

void FadedLed::On()
{
	state = HIGH;
	maxBrightness = 255;
	timer.SetInterval(30);
}

void FadedLed::Off()
{
	state = LOW;
	maxBrightness = 0;
	timer.SetInterval(30);
}

void FadedLed::SetBrightness(byte bright)
{
	this->maxBrightness = bright;
	if (bright > 0)
	{
		state = HIGH;
	}
	else
	{
		state = LOW;
	}

	if (!timer.IsStarted())
	{
		timer.SetInterval(5);
	}
}

void FadedLed::Loop()
{
	if (timer.TimePassed())
	{
		Serial.println(brightness);

		if (brightness > maxBrightness)
		{
			brightness -= fadeAmount;
			if (brightness < maxBrightness)
			{
				brightness = maxBrightness;
				timer.Stop();
			}
		}
		else
		{
			brightness += fadeAmount;
			if (brightness > maxBrightness)
			{
				brightness = maxBrightness;
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

