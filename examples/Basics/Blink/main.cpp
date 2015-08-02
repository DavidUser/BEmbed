/*
   Blink
   Turns LED on and off by one second, repeatedly.
*/

#include <DigitalPin.h>
#include <time.h>
using namespace zeus;

main() {
	DigitalPin led(13); //pin 13 are represented by this object named led
	
	while(true) { //do this repeatedly forever
		led.turnOn(); // put high voltage on pin
		delay(1_seconds); //1 second delay, using user-defined literals (C++11)
		led.turnOff(); // put low voltage on pin
		delay(1_seconds); //1 second delay
	}
}
