// Mistumi95SP9PUnipolar.h

#ifndef _MISTUMI95SP9PUNIPOLAR_h
#define _MISTUMI95SP9PUNIPOLAR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Stepper\Stepper.h"

class Mistumi95SP9PUnipolar
{
 private:
	 Stepper stepper;
 public:
	 Mistumi95SP9PUnipolar(int pin1, int pin2, int pin3, int pin4);
	 void Step(int steps);
	 void SetSpeed(int speed);
	 static const int STEPS = 48;
};

#endif

