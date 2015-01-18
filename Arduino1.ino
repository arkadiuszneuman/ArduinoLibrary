#include "RobotMotor.h"
#include "RobotLCD.h"
#include "RobotSteeringWheel.h"
#include "Mistumi95SP9PUnipolar.h"
#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "BrightnessLed.h"
#include "FadedLed.h"
#include "Blinker.h"
#include "Stepper\Stepper.h"
#include "SensorHCSR04.h"
#include "led.h"

//
//LiquidCrystal_I2C	lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the I2C bus address for an unmodified backpack
////
//void setup()
//{
//	// activate LCD module
//	lcd.begin(16, 2); // for 16 x 2 LCD module
//	lcd.setBacklightPin(3, POSITIVE);
//	lcd.setBacklight(HIGH);
//
//}
//
//int i = 0;
//
//void loop()
//{
//	++i;
//	lcd.home(); // set cursor to 0,0
//	lcd.print("Arek");
//	lcd.setCursor(0, 1);        // go to start of 2nd line
//	lcd.print("Sekundy: ");
//	lcd.print(i);
//
//	//delay(1000);
//	//lcd.setBacklight(LOW);      // Backlight off
//	//delay(250);
//	//lcd.setBacklight(HIGH);     // Backlight on
//	delay(1000);
//}

//const int buttonPin = 2;     // the number of the pushbutton pin
//const int ledPin = 13;      // the number of the LED pin
//
//// variables will change:
//int buttonState = 0;         // variable for reading the pushbutton status
//
//LiquidCrystal_I2C	lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the I2C bus address for an unmodified backpack

//BrightnessLed led(11);
////Blinker motor(new FadedLed(11, 2), 5000, 5000);
//int i = 0;
//void setup() {
//	//// initialize the LED pin as an output:
//	//pinMode(motorPin, OUTPUT);
//	//// initialize the pushbutton pin as an input:
//	//pinMode(buttonPin, INPUT);
//
//	//lcd.begin(16, 2); // for 16 x 2 LCD module
//	//lcd.setBacklightPin(3, POSITIVE);
//	//lcd.setBacklight(HIGH);
//	Serial.begin(9600);
//	led.SetBrightness(i);
//}
//void loop(){
//	//motor.Loop();
//
//	/*int current = readSerial();
//	if (current > 0 && current != i)
//	{
//		i = current;
//		led.SetBrightness(i);
//		Serial.println(i);
//	}*/
//
//	led.SetBrightness(160);
//}
//
//String inString = "";    // string to hold input
//
//int readSerial()
//{
//	// Read serial input:
//	while (Serial.available() > 0) {
//		int inChar = Serial.read();
//		if (isDigit(inChar)) {
//			// convert the incoming byte to a char 
//			// and add it to the string:
//			inString += (char)inChar;
//		}
//		// if you get a newline, print the string,
//		// then the string's value:
//		if (inChar == '\n') {
//			int toReturn = inString.toInt();
//			inString = "";
//
//			return toReturn;
//		}
//	}
//}
//
//

SensorHCSR04 sensor(12, 13);
RobotMotor motor;
RobotSteeringWheel steeringWheel;

void setup() {
	RobotLCD::Init();
	motor.MoveForward();
}

//stepper
void loop(){
	//stepper.step(STEPS*36);
	/*stepper.Step(stepper.GetSteps() * 57);
	delay(1000);*/
	//stepper.step(-STEPS * 20);
	//delay(500);

	

	//steeringWheel.TurnLeft();
	//delay(1000);
	//steeringWheel.TurnStaight();
	//delay(1000);
	//steeringWheel.TurnRight();
	//delay(1000);

	/*int dist = sensor.GetCmDistance();
	RobotLCD::Write(dist);
	delay(1000);*/

	int distance = sensor.GetOneMeasure();
	if (distance > 0)
	{
		RobotLCD::Write(distance);

		if (distance <= 15)
		{
			for (int i = 0; i < 3; ++i)
			{
				turnAround();
			}
		}
	}

	delay(500);
}

void turnAround()
{
	int motorDelay = 2000;

	motor.Stop();
	steeringWheel.TurnLeft();
	motor.MoveBackward();
	delay(motorDelay);
	motor.Stop();
	steeringWheel.TurnRight();
	motor.MoveForward();
	RobotLCD::Write("Prosto przy skrecie");
	delay(motorDelay + (((float)motorDelay) / 6));
	motor.Stop();
	RobotLCD::Write("Prostuje");
	steeringWheel.TurnStaight();
	motor.MoveForward();
}