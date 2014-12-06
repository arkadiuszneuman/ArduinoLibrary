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

void Led::On()
{
	digitalWrite(pin, HIGH);
	state = HIGH;
}

void Led::Off()
{
	digitalWrite(pin, LOW);
	state = LOW;
}

int Led::GetState()
{
	return state;
}

void Led::Loop()
{
}

