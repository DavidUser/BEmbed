/*
   Analog input, analog output, serial output

   Reads an analog input pin, maps the result to a range from 0 to 255
   and uses the result to set the pulsewidth modulation (PWM) of an output pin

   The circuit:
   * potentiometer connected to analog pin 0.
     Center pin of the potentiometer goes to the analog pin.
     side pins of the pontentiometer go to +5V and ground
   * LED connected from digital pin 9 to ground
   */

#include <map.h>
#include <time.h>
#include <AnalogPin.h>
using namespace zeus;

main() {
	const AnalogPin potentiometer(A0); // object potentiometer represents the analog readable pin A0
	const PWMPin led(9); // object led represents the PWM writable pin 9
	const Serial usb; // object usb represents the USB Serial connection, with 9600Hz baund rate (by default)

	while(true) { // repreat forever
		int sensorValue = potentiometer.read(); // read the potentiometer analog value
		/* maps the potentiometer value to led fade value, 
		   ranges of values get by the member function getLimits() */
		int ledFade = map(sensorValue, potentiometer.getLimits(), led.getLimits());

		led.write(ledFade); // set brigthness of led
		// write via serial the input values of system and the output values
		usb << "sensor = " << sensorValue << '\t'
			<< " output = " << ledFade << endl;
		
		delay(2_milliseconds); // wait 2 ms
	}
}
