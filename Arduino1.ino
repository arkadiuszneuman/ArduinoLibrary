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





	/*int distance = sensor.GetOneMeasure();
	if (distance > 0)
	{
		RobotLCD::Write(distance);

		if (distance <= 15)
		{
			for (int i = 0; i < 1; ++i)
			{
				turnAround();
			}
		}
	}

	delay(500);*/

	delay(2000);
	motor.Stop();
	delay(5000);
	motor.MoveBackward();
	delay(2000);
	motor.MoveForward();
	delay(1000);
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

//#define IN1  4
//#define IN2  5
//#define IN3  6
//#define IN4  7
//int Steps = 0;
//boolean Direction = true;// gre
//unsigned long last_time;
//unsigned long currentMillis;
//int steps_left = 4095;
//long time;
//void setup()
//{
//	pinMode(IN1, OUTPUT);
//	pinMode(IN2, OUTPUT);
//	pinMode(IN3, OUTPUT);
//	pinMode(IN4, OUTPUT);
//	// delay(1000);
//
//}
//void loop()
//{
//	while (steps_left>0){
//		currentMillis = micros();
//		if (currentMillis - last_time >= 1000){
//			stepper(1);
//			time = time + micros() - last_time;
//			last_time = micros();
//			steps_left--;
//		}
//	}
//	delay(1000);
//	Direction = !Direction;
//	steps_left = 4095;
//}
//
//void stepper(int xw){
//	for (int x = 0; x<xw; x++){
//		switch (Steps){
//		case 0:
//			digitalWrite(IN1, LOW);
//			digitalWrite(IN2, LOW);
//			digitalWrite(IN3, LOW);
//			digitalWrite(IN4, HIGH);
//			break;
//		case 1:
//			digitalWrite(IN1, LOW);
//			digitalWrite(IN2, LOW);
//			digitalWrite(IN3, HIGH);
//			digitalWrite(IN4, HIGH);
//			break;
//		case 2:
//			digitalWrite(IN1, LOW);
//			digitalWrite(IN2, LOW);
//			digitalWrite(IN3, HIGH);
//			digitalWrite(IN4, LOW);
//			break;
//		case 3:
//			digitalWrite(IN1, LOW);
//			digitalWrite(IN2, HIGH);
//			digitalWrite(IN3, HIGH);
//			digitalWrite(IN4, LOW);
//			break;
//		case 4:
//			digitalWrite(IN1, LOW);
//			digitalWrite(IN2, HIGH);
//			digitalWrite(IN3, LOW);
//			digitalWrite(IN4, LOW);
//			break;
//		case 5:
//			digitalWrite(IN1, HIGH);
//			digitalWrite(IN2, HIGH);
//			digitalWrite(IN3, LOW);
//			digitalWrite(IN4, LOW);
//			break;
//		case 6:
//			digitalWrite(IN1, HIGH);
//			digitalWrite(IN2, LOW);
//			digitalWrite(IN3, LOW);
//			digitalWrite(IN4, LOW);
//			break;
//		case 7:
//			digitalWrite(IN1, HIGH);
//			digitalWrite(IN2, LOW);
//			digitalWrite(IN3, LOW);
//			digitalWrite(IN4, HIGH);
//			break;
//		default:
//			digitalWrite(IN1, LOW);
//			digitalWrite(IN2, LOW);
//			digitalWrite(IN3, LOW);
//			digitalWrite(IN4, LOW);
//			break;
//		}
//		SetDirection();
//	}
//}
//void SetDirection(){
//	if (Direction == 1){ Steps++; }
//	if (Direction == 0){ Steps--; }
//	if (Steps>7){ Steps = 0; }
//	if (Steps<0){ Steps = 7; }
//}