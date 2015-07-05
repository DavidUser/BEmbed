/*
   DigitalReadSerial
   Reads a digital input on  pin 2, prints the result to the serial monitor
*/

#include <digitalInput.h>

main() {
	Pin button(2); // object button represent the pin 2
	Serial usb; // object usb represent the serial connection, using 9600 hz default bound rate

	while(true) { //do this check forever
		bool buttonState = button.read(); //read button state high (true) or low (false)

		usb << buttonState << endl; // write to usb the button state and start a newline
		delay(1_seconds); // wait 1 second, using user-defined literals (C++11)
	}
}
