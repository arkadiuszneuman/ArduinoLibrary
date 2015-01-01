#include "RobotSteeringWheel.h"

RobotSteeringWheel::RobotSteeringWheel()
	: stepper(0, 1, 2, 3)
{
	direction = straight;
	stepper.SetSpeed(300);
}

void RobotSteeringWheel::TurnLeft()
{
	RobotLCD::Write("Skrecam w lewo");
	if (direction == straight)
	{
		stepper.Step(-fullRotation / 8);
	}
	else if (direction == right)
	{
		stepper.Step(-fullRotation / 4);
	}
	direction = left;
}

void RobotSteeringWheel::TurnRight()
{
	RobotLCD::Write("Skrecam w prawo");
	if (direction == straight)
	{
		stepper.Step(fullRotation / 8);
	}
	else if (direction == left)
	{
		stepper.Step(fullRotation / 4);
	}
	direction = right;
}

void RobotSteeringWheel::TurnStaight()
{
	RobotLCD::Write("Skrecam prosto");
	if (direction == left)
	{
		stepper.Step(fullRotation / 8);
	}
	else if (direction == right)
	{
		stepper.Step(-fullRotation / 8);
	}
	direction = straight;
}