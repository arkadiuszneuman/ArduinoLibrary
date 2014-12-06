

#include "Timer.h"
#include "FadedLed.h"
#include "LedBlinker.h"

LedBlinker ledBlinker(11, 3000, 3000);

void setup() {

}


void loop() {
	ledBlinker.Loop();
}