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

void RobotMotor::MoveForward()
{
	RobotLCD::Write("Jade w przod");

	backwardPin.Off();
	if (!isForward && !isStopped)
	{
		delay(1000);
	}
	isForward = true;
	forwardPin.On();
}

void RobotMotor::MoveBackward()
{
	RobotLCD::Write("Jade w tyl");

	forwardPin.Off();
	if (isForward && !isStopped)
	{
		delay(1000);
	}
	isForward = false;
	backwardPin.On();
}

void RobotMotor::Stop()
{
	RobotLCD::Write("Stop");

	forwardPin.Off();
	backwardPin.Off();
	isStopped = true;
}