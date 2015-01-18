// 
// 
// 

#include "BrightnessLed.h"

BrightnessLed::BrightnessLed(int pin)
{
	this->pin = pin;
	pinMode(pin, OUTPUT);
}

void BrightnessLed::SetBrightness(byte brightness)
{
	this->brightness = brightness;

	if (brightness == 255)
	{
		digitalWrite(pin, HIGH);
	}
	else if (brightness == 0)
	{
		digitalWrite(pin, LOW);
	}
	else
	{
		analogWrite(pin, brightness);
	}
}

byte BrightnessLed::GetBrightness()
{
	return brightness;
}