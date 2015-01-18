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
	/*int toChange = 170;
	int pinBrightness = pin.GetBrightness();

	if (pinBrightness < toChange)
	{
		toChange -= pinBrightness;
	}

	for (int i = 0; i <= toChange; ++i)
	{
		pin.SetBrightness(pinBrightness - i);
		delay(5);
	}*/
	SmoothStart(pin, 100);
	pin.SetBrightness(0);
}

void RobotMotor::SmoothStart(BrightnessLed& pin, byte speed)
{
	byte pinBrightness = pin.GetBrightness();
	int change = speed - pinBrightness;

	if (change >= 0)
	{
		for (int i = 0; i <= change; ++i)
		{
			RobotLCD::Write(pinBrightness + i);
			pin.SetBrightness(pinBrightness + i);
			delay(7);
		}
	}
	else
	{
		
		for (int i = pinBrightness; i >= pinBrightness + change; --i)
		{
			RobotLCD::Write(i);
			pin.SetBrightness(i);
			delay(7);
		}
	}

	/*byte toChange = speed - 105;

	if (pinBrightness > toChange)
	{
		toChange = toChange - (pinBrightness - toChange);
	}

	pinBrightness = speed - toChange;

	for (int i = 0; i <= toChange; ++i)
	{
		RobotLCD::Write(pinBrightness + i);

		pin.SetBrightness(pinBrightness + i);
		delay(7);
	}*/
}

byte RobotMotor::GetSpeedFromPercent(byte percent)
{
	if (percent == 0)
	{
		return 0;
	}

	int value = (percent * 150) / 100;
	return (byte)(value + 105);
}

void RobotMotor::MoveForward(byte percent)
{
	RobotLCD::Write("Jade w przod");

	if (!isForward && !isStopped)
	{
		SmoothStop(backwardPin);
	}

	isForward = true;
	isStopped = false;

	SmoothStart(forwardPin, GetSpeedFromPercent(percent));
}

void RobotMotor::MoveBackward(byte percent)
{
	RobotLCD::Write("Jade w tyl");

	if (isForward && !isStopped)
	{
		SmoothStop(forwardPin);
	}

	isForward = false;
	isStopped = false;

	SmoothStart(backwardPin, GetSpeedFromPercent(percent));
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