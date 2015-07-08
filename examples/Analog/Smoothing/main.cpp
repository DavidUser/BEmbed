/*
   Smoothing

   Reads repeatedly from an analog input, calculating a running averange
   and printing it to the computer. Keeps ten readings in an array and
   continually averanges them.

   The circuit:
   * Analog sensor (potentiometer will do) attached to analog input A0
   */

#include <AnalogPin.h>
#include <Serial.h>
#include <time.h>
using namespace zeus;

main() {
	/* Define the number of samples to keep track of. The higher the number,
	   the more the reading will be smoothed, but the slower the outrput will
	   respond to the input. Using a constant rather than a normal variable lets
	   use this value to determine the size of the readings array. */
	const unsigned NUMBER_OF_READINGS = 10;
	unsigned readings[NUMBER_OF_READINGS] = {0}; // initialize all positions with zero 
	unsigned long total = 0; // the running total
	unsigned averange = 0; // the running averange

	AnalogPin sensor(A0); // sensor object, represents the analog readable pin A0
	Serial usb; // usb object, represents the USB serial connection

	for (unsigned i = 0; true; i = (i + 1) % NUMBER_OF_READINGS) { // repreat forever 
		total -= readings[i]; // subtract the replaced value
		readings[i] = sensor.read(); // repleace a older value by the new sensor value
		total += readings[i]; // add to total the new sensor value

		auto averange = total / NUMBER_OF_READINGS; // calculate the running averange
		usb << averange << endl; // put on serial the averange running value
		delay(1_seconds); // wait 1 second
	}
}
