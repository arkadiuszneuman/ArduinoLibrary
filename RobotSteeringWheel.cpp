#include "RobotSteeringWheel.h"

RobotSteeringWheel::RobotSteeringWheel()
	: stepper(8, 9, 10, 11)
{
	direction = straight;
	fullRotation = 48 * 57 * 2;
	stepper.SetSpeed(250);
}

void RobotSteeringWheel::TurnLeft()
{
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