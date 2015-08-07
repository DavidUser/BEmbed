/*
   Ping Sensor

   This code reads a PING ultrasonic rangefinder and returns the 
   distance to the closest object in range. To do this, it sends a pulse 
   to the sensor to initiate a reading, then listens for a pulse to return.
   The length of the returning pulse is proportional to the distance of 
   the object from  the sensor.

   The circuit:
   * +V connection of the PING attached to +5V
   * GND connection of the PING attached to  ground
   * SIG connection of the PING attached to  digital pin 7
   */

#include <PWMPin.h>
#include <Serial.h>
#include <time.h>
using namespace zeus;

main() {
	PulsePin pingSensor(7); // represent the digital pin 7 capable of write and read pulses
	Serial usb; // represent the USB connection

	while (true) { // repeat forever
		pingSensor.write(5_millisenconds); // trigger a single HIGH pulse with 5 ms of duration
		unsigned long duration = pingSensor.read(); // read the duration of the single pulse input
		
		// using the speed of sound calculate the distance, speed of sound: 73.746 ms/in or 29 ms/cm
		// divide by 2 because the sound wave goes to the object and come back so travel twice the distance
		auto inches = duration / 74 / 2; // convert the duration to distance in inches; 
		auto centimeters = duration / 29 / 2; // convert the duration to distace in centimeters 

		usb << inches << " in, " << centimeters << " cm." << endl; // print the distance
		delay(100_millisenconds); // wait 100 ms
	}
}
