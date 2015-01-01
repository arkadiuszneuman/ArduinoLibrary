// RobotLCD.h

#ifndef _ROBOTLCD_h
#define _ROBOTLCD_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//#include "Wire.h"
//#include "LCD.h"
#include "LiquidCrystal_I2C.h"

class RobotLCD
{
private:
	static LiquidCrystal_I2C lcd;
	static String firstLine;
	static String secondLine;
public:
	static void Init();
	static void Write(String txt);
	static void Write(int txt);
};

#endif

