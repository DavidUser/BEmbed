/*
   Memsic2125

   Read the Memsic 2125 two-axis accelerometer. Converts the pulses
   output by the 2125 into milli-g's (1/1000 of earth's gravity)
   and prints them over the serial connection to the computer

   The circuit:
   * X output of accelerometer to digital pin 2
   * Y output of accelerometer to digital pin 3
   * +V of accelerometer to +5V
   * GND of accelerometer to ground
   */

#include <PWMPin.h>
#include <Serial.h>
#include <time.h>
using namespace zeus;

main() {
	PWMPin xPulsePin(2), yPulsePin(3); // represents the pulse width read where the pins are connected
	struct { unsigned x, y; } acceleration; // acceletation with components x and y
	Serial usb; // represents the USB connection

	while (true) { // repreat forever
		// read the pulses width and convert to milli-g's
		acceleration.x = (xPulsePin.readPulse() / 10 - 500) * 8; 
		acceleration.y = (yPulsePin.readPulse() / 10 - 500) * 8;

		usb << acceleration.x << '\t' << acceleration.y << endl; // prints the accelation components
		delay(100_milliseconds); // wait 100 ms
	}
}
