#include "Mistumi95SP9PUnipolar.h"

Mistumi95SP9PUnipolar::Mistumi95SP9PUnipolar(int pin1, int pin2, int pin3, int pin4)
	: stepper(STEPS, pin1, pin2, pin3, pin4)
{
}

void Mistumi95SP9PUnipolar::SetSpeed(int speed)
{
	stepper.setSpeed(speed);
}

void Mistumi95SP9PUnipolar::Step(int steps)
{
	stepper.step(steps);
}