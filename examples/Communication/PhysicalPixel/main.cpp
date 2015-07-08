/*
   Physical Pixel

   An example of using the board to receive data from the computer.
   In this case, the boards turn on an LED when it receive the character
   'H' and turns off the LED when it receives the character 'L'.
   */

#include <Serial.h>
#include <Pin.h>
using namespace zeus; // using Serial and Pin from namespace zeus

main() {
	Serial usb; // usb object, represents the USB serial connection
	Pin led(13); // led object, represents the digital output pin 13

	while(usb.connected()) { // while usb is connected
		char character;

		usb >> character; // reads the character via serial
		// if it's a capital H (ASCII 72), turn on the LED.
		if (character == 'H') led.turnOn();
		// if it's a capital L (ASCII 76), turn off the LED.
		if (character == 'L') led.turnOff();
	}
}
