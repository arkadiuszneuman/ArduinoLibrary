

#include "Timer.h"
#include "FadedLed.h"
#include "Blinker.h"

Blinker ledBlinker(new Led(11), 1000, 1000);

void setup() {

}


void loop() {
	ledBlinker.Loop();
}