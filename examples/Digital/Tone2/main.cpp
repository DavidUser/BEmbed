/*
   Pitch follower

   Plays a pitch that changes based on a changing analog input

   circuit:
   * 8-ohm speaker on digital pin 9
   * photoresistor on analog A0 to 5V
   * 4.7K resistor on analog A0 to ground
   */

#include <Tone.h>
#include <AnalogPin.h>
#include <Serial.h>
#include <map.h>
#include <time.h>
using namespace zeus;

main() {
	Tone speaker(9); // object speaker represents the pin 9 to play tones
	AnalogPin photoresistor; // object photoresistor represents the analog pin A0
	Serial usb; // object usb represents the serial connection

	while (true) { // do this forever
		int sensorReading = photoresistor.read();

		usb << sensorReading << endl; // output the sensor reading and create a new line

		/* map the analog input range (in this case, 400 - 1000 from the photoresistor)
		   to the output pitch range (120 - 1500Hz)
		   change the minimum and maximum input numbers below
		   depending on the range your sensor's giving:
		 */
		int pitch = map(sensorReading, 400, 1000, 120, 1500);

		speaker.play(pitch, 10_milliseconds); // play the pitch by 10 milliseconds
		delay(1_seconds); // wait 1 second
	}
}
