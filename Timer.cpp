#include "Timer.h"

Timer::Timer(unsigned long interval)
{
	SetInterval(interval);
}

void Timer::SetInterval(unsigned long interval)
{
	this->interval = interval;
	this->isStarted = interval > 0;
	Reset();
}

void Timer::Reset()
{
	this->previousMillis = millis();
}

void Timer::Start()
{
	isStarted = true;
}

void Timer::Stop()
{
	isStarted = false;
}

bool Timer::IsStarted()
{
	return isStarted;
}

bool Timer::TimePassed()
{
	if (isStarted)
	{
		unsigned long currentMillis = millis();

		if (currentMillis < previousMillis)
		{
			previousMillis = 0;
		}

		bool isPassed = currentMillis - previousMillis > interval;

		if (isPassed)
		{
			Reset();
		}

		return isPassed;
	}
	else
	{
		return false;
	}
}


