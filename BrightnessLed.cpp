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
	analogWrite(pin, brightness);
}