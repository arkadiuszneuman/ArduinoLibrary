#include "SensorHCSR04.h"

SensorHCSR04::SensorHCSR04(int triggerPin, int echoPin)
{
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);

	this->triggerPin = triggerPin;
	this->echoPin = echoPin;
}

int SensorHCSR04::GetCmDistance()
{
	int difference;
	int distanceOne;
	int distanceTwo;


		do
		{
			distanceOne = GetOneMeasure();
			delay(3);
			distanceTwo = GetOneMeasure();

			difference = abs(distanceOne - distanceTwo);
		}
		while (difference > 3);

	return (distanceOne + distanceTwo) / 2;
	//return GetOneMeasure();
}

int SensorHCSR04::GetOneMeasure()
{
	digitalWrite(triggerPin, LOW);  // Added this line
	delayMicroseconds(2); // Added this line
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10); // Added this line
	digitalWrite(triggerPin, LOW);
	long duration = pulseIn(echoPin, HIGH, 10000);
	long distance;

	if (duration > 0)
	{
		distance = (duration / 2) / 29.1;
	}
	else
	{
		distance = -1;
	}


	if (distance > 500 || distance < 0)
	{
		return -1;
	}

	return distance;
}