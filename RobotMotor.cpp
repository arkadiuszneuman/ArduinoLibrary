// 
// 
// 

#include "RobotMotor.h"

RobotMotor::RobotMotor()
	: forwardPin(10), backwardPin(9)
{
	isForward = false;
	isStopped = true;
}

void RobotMotor::SmoothStop(BrightnessLed& pin)
{
	int toChange = 150;
	int pinBrightness = pin.GetBrightness();

	if (pinBrightness > toChange)
	{
		toChange = pinBrightness - toChange;
	}

	for (int i = 0; i <= toChange; ++i)
	{
		pin.SetBrightness(pinBrightness - i);
		delay(4);
	}
	pin.SetBrightness(0);
}

void RobotMotor::SmoothStart(BrightnessLed& pin)
{
	byte toChange = 150;
	byte pinBrightness =  pin.GetBrightness();

	if (pinBrightness > toChange)
	{
		toChange = toChange - (pinBrightness - toChange);
	}

	pinBrightness = 255 - toChange;

	for (int i = 0; i <= toChange; ++i)
	{
		pin.SetBrightness(pinBrightness + i);
		delay(7);
	}
}

void RobotMotor::MoveForward()
{
	RobotLCD::Write("Jade w przod");

	if (!isForward && !isStopped)
	{
		SmoothStop(backwardPin);
	}

	isForward = true;
	isStopped = false;

	SmoothStart(forwardPin);
}

void RobotMotor::MoveBackward()
{
	RobotLCD::Write("Jade w tyl");

	if (isForward && !isStopped)
	{
		SmoothStop(forwardPin);
	}

	isForward = false;
	isStopped = false;

	SmoothStart(backwardPin);
}

void RobotMotor::Stop()
{
	if (!isStopped)
	{
		RobotLCD::Write("Stop");


		if (isForward)
		{
			SmoothStop(forwardPin);
		}
		else
		{
			SmoothStop(backwardPin);
		}

		isStopped = true;
	}
}