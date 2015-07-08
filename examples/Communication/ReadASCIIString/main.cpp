/*
   Reading a serial ASCII-encoded string

   This sketch demonstrates the parse int feature.
   It looks for an ASCII string of comma-separated values.
   It parses them into ints and uses those to fade an RGB LED.

   The circuit: Common-anode RGB LED wired like so:
   * Red cathode: digital pin 3
   * Green cathode: digital pin 
   * Blue cathode: digital pin 6
   * anode: +5V
   */

#include <Serial.h>
#include <PWMPin.h>
#include <constrain.h>
using namespace zeus;

main() {
	Serial usb; // usb object, represents the USB serial connection
	usb.setDelimiter(','); // set from the space (default) delimiter to comma; final delimiter is \n (default)

	struct {
		PWMPin red(3), green(5), blue(6); // PWM output pins
	} led; // represents the LED RGB

	while (usb.connected()) { // while usb connected
		int red, green, blue;	

		usb >> red >> green >> blue; // reads the integer values, pass by USB
		// constrain the values and invert
		// if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
		red = 255 - constrain(red, 0, 255);
		green = 255 - constraint(green, 0, 255);
		blue = 255 - constraint(blue, 0, 255);

		// fade the red, green and blue legs of the LED:
		led.red.write(red);
		led.green.write(green);
		led.blue.write(blue);

		// print the three numbers in one string as hexadecimal:
		usb << usb::hex << red << green << blue << endl;
	}
}
