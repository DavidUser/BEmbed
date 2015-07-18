/*
   ADXL3xx Accelerometer

   Reads an Analog Device ADLX3xx accelerometer and communicates the
   acceleration to the computer. The pins used are designed to be easily
   compatible with the breakout boards from Sparkfun, avalible from:
	http://www.sparkfun.com/commerce/categories.php?c=80
   
   The circuit:
   * analog 0: accelerometer self test
   * analog 1: z-axis
   * analog 2: y-axis
   * analog 3: x-axis
   * analog 4: ground
   * analog 5: vcc
   */

#include <AnalogPin.h>
#include <Serial.h>
#include <time.h>
#include <Pin.h>
using namespace zeus;

main() {
	Pin groundPin(18), powerPin(19); // using A4 and A5 like digital output pins 

	groundPin.turnOff(); // put low voltage on ground pin
	powerPin.turnOn(); // put high voltage on power pin

	AnalogPin xPin(A3), yPin(A2), zPin(A1); // objects that represent analog input pins A1, A2 and A3
	Serial usb; // usb object, represent the serial USB connection

	while(true) {
		// print the sensor values on usb
		usb << xPin.read() << '\t' // sensor read x
		       	<< yPin.read() << '\t' // sensor read y
 			<< zPin.read() << endl; // sensor read z
		delay(100_milliseconds); // wait 100ms
	}
}
