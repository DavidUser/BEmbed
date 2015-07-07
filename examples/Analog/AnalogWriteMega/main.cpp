/*
   Mega pwm write test

   This sketch fades LEDs up and down one at a time on digital pins 2 through 13.
   This sketch was written for the Arduino Mega, and will not work on previous boards,
   however with few modifications this can work similar with other boards

   * Note: using ',' terminator of C++98 (standard),
   this works like ';' however the comands are put on the same execution line

   The circuit:
   * LEDs attached from pins 2 through 13 to ground
   */

#include "analogOutput.h"

main() {
	std::vector<PWMPin> leds = PWMPin::getRange(2,13); // get a vector of a range of pwm pins, pin 2 until 13

	for (PWMPin led : leds) { // for each led, using C++03 foreach syntax
		for (unsigned brightness = 0; brightness < 255; ++brightness)
			led.write(brightness), delay(2_milliseconds); // set brightness of led and wait 2ms 
		for (unsigned brightness = 255; brightness >= 0; --brightness)
			led.write(brightness), delay(2_milliseconds); // set brightness of led and wait 2ms
		delay(100_milliseconds); // wait 100ms
	}
}
