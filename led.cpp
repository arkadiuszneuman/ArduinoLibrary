// 
// 
// 

#include "led.h"

Led::Led(int pin)
{
	this->pin = pin;
	pinMode(pin, OUTPUT);
	this->state = LOW;
}

void Led::LedOn()
{
	digitalWrite(pin, HIGH);
	state = HIGH;
}

void Led::LedOff()
{
	digitalWrite(pin, LOW);
	state = LOW;
}

int Led::GetState()
{
	return state;
}

