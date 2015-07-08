/*
   Button
   Turns on and off a light emitting diode (LED) connected to digital
   pin 13, when pressing a bushbutton attached to pin 2.

   The circuit:
   * LED attached from pin 13 to ground
   * pushbutton attached to pin 2 from +5V
   * 10K resistor attached to pin 2  from ground

   * Note: on most Arduinos there is already an LED on the board
   attached to pin 13
   */

#include <Pin.h>
#include <SignalInterruption.h>
using namespace zeus;

Pin button(2); // object button represent the digital pin 2
Pin led(13); // object led represent the digital pin 13

// function called when a pin change your state
void buttonStateToLED() {
	led.toggle(); // toggle the led state
}

main() {
	/* An interruption stop the normal working of microcontroller and run another work,
	   in this case every change on pin represented by button will stop the normal working of microcontroller
	   and call the buttonStateToLED() function, then it'll return to the normal work until the next change
	   on pin represented by button
	   */
	SignalInterruption buttonPress(TOGGLE, button, buttonStateToLED); // buttonPress object represent a hardware interruption detecting toggle on pin button and call the buttonStateToLED() function
}
