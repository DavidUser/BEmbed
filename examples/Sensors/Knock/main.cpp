/*
   Knock Sensor

   This sketch reads a piezo element to detect a knocking sound.
   It reads an analog pin and compares the result to a set threshold.
   If the result is greater than the threshold, it writes
   "knock" to the serial port, and toogles the LED on pin 13.

   The circuit:
   * + connection of the piezo attached to analog in A0
   * - connection of the piezo attached to ground
   * 1-megohm resistor attached from analog in 0 to ground
   */

#include <AnalogPin.h>
#include <Serial.h>
#include <Pin.h>
#include <time.h>
using namespace zeus;

main() {
	AnalogPin sensor(A0); // sensor object, represents the analog pin A0 where piezo are attached
	Pin led(13); // led object, represents the digital pin 13 where led is attached
	Serial usb; // usb object, represents the USB serial connection default (USB, 9600)
	const unsigned THRESHOLD = 100; // knock is detected as from threshold

	while (true) { // repreat forever
		if (sensor.read() >= THRESHOLD) { // sensor reading exceeds the threshold defined
			led.toogle(); // toogle the led state
			usb << "knock" << endl; // prints to usb knock
		}
		delay(100_milliseconds); // wait 100ms
	}
}
