// LedBlinker.h

#ifndef _ILED_h
#define _ILED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class ISwitchable
{
public:
	virtual void On() = 0;
	virtual void Off() = 0;
	virtual void Loop() = 0;
	virtual int GetState() = 0;
};

#endif

