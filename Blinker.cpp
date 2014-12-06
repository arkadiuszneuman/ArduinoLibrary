#include "Blinker.h"

Blinker::Blinker(ISwitchable* led, int intervalOn, int intervalOff)
{
	this->switchable = led;
	SetIntervals(intervalOn, intervalOff);
}

void Blinker::SetIntervals(int intervalOn, int intervalOff)
{
	this->intervalOn = intervalOn;
	this->intervalOff = intervalOff;

	if (switchable->GetState() == LOW)
	{
		timer.SetInterval(intervalOff);
	}
	else
	{
		timer.SetInterval(intervalOn);
	}
}

void Blinker::Loop()
{
	switchable->Loop();
	
	if (timer.TimePassed())
	{
		if (switchable->GetState() == LOW)
		{
			timer.SetInterval(intervalOn);
			switchable->On();
		}
		else
		{
			timer.SetInterval(intervalOff);
			switchable->Off();
		}
	}
}

Blinker::~Blinker()
{
	delete switchable;
	switchable = NULL;
}
