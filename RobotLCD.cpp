#include "RobotLCD.h"

LiquidCrystal_I2C RobotLCD::lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the I2C bus address for an unmodified backpack

//RobotLCD::RobotLCD()
//	: lcd(0x27, 2, 1, 0, 4, 5, 6, 7) // 0x27 is the I2C bus address for an unmodified backpack
//{
//	//this->Init();
//}

String RobotLCD::firstLine = "";
String RobotLCD::secondLine = "";

void RobotLCD::Init()
{
	lcd.begin(16, 2); // for 16 x 2 LCD module
	lcd.setBacklightPin(3, POSITIVE);
	lcd.setBacklight(HIGH);
}

void RobotLCD::Write(String txt)
{
	secondLine = firstLine;
	firstLine = txt;

	lcd.clear();
	lcd.home();
	lcd.print(txt);
	//lcd.setCursor(0, 1);
	//lcd.print(secondLine);
}

void RobotLCD::Write(int txt)
{
	//secondLine = firstLine;
	//firstLine = txt;

	lcd.clear();
	lcd.home();
	lcd.print(txt);
	//lcd.setCursor(0, 1);
	//lcd.print(secondLine);
}
