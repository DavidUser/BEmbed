/*
   State change detection (edge detection)

   Often you don't need to know the state of a digital input all the time,
   but you just need to know when the input changes from one state to another.
   For example, you want to know when a button goes from OFF to ON. This is called
   state change detection, or edge detection.

   This example shows how to detect when a button or button changes from off to on
   and on to off

   The circuit:
   * pushbutton attached to pin 2 from +5V
   * 10K resistor attached to pin 2 from ground
   * LED attached from pin 13to ground (or use the buit-in LED on
   most Arduino boards)
   */

#include <Pin.h>
#include <SignalInterruption.h>
using namespace zeus;

const Pin button(2);
const Pin led(13);

unsigned int buttonPushCounter = 0;

void countButtonPress() {
	buttonPushCounter++;
}

main() {
	/* Interruption stop normal microcontroller work and run another work,
	   in this case at every RISING (chage from low to high state) on the
	   pin represented by button, the countButtonPress() function will be called,
	   then the microcontroller will back to the normal work.
	   */
	SignalInterruption buttonPressed(RISING, button, countButtonPress);

	while(true) // repeat forever
		if (buttonPushCounter % 4 == 0) // at every four pushes
			led.turnOn(); // put high voltage on pin
		else
			led.turnOff(); // put low voltage on pin
}
