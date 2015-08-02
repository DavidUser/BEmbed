/*
   Input Pullup Serial

   This example demonstrates the use of Pin with pullup configuration. It reads a
   digital input on pin 2 and prints the results to the serial monitor.

   The circuit:
   * Momentary switch attached from pin 2 to ground
   * Buit-in LED on pin 13

   Unlike the normal Pin configuration, there is no pull-down resistor necessarry.
   An internal 20K-ohm resistor is pulled to 5V. This configuration causes the input to
   read HIGH when the switch is open and LOW when it is closed

   This pullup configuration enable a onboard pullup circuit
   */

#include <DigitalPin.h>
#include <Serial.h>
using namespace zeus;

main() {
	DigitalPin button(2, PULLUP); // object button represents the digital pin 2
	DigitalPin led(13); // object led represents the digital pin 13

	Serial usb; // object usb represents the serial connection

	while(true) { // repreat forever
		bool buttonState = button.getState(); // get the digital pin state

		usb << (buttonState? "high":"low") << endl; // output via serial the button State and create a new line

		// mirror the state of the button on the led
		if (buttonState == HIGH)
			led.turnOn();
		else
			led.turnOff();
	}
}
