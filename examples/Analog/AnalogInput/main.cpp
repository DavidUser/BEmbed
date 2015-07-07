/*
   Analog Input

   Demonstrates analog input by reading an analog sensor on analog pin 0 and
   turning on and off a light emitting diode (LED) connected to digital pin 13.
   The amount of time the LED will be on and off depends on
   the value obtained by the read on analog pin of potentiometer

   The circuit:
   * Potentiometer attached to analog input 0
   * center pin of the potentiometer to the analog pin
   * one side pin (either one) to ground
   * the other side pin to +5V
   * LED anode (long leg) attached to digital output 13
   * LED cathode (short leg) attached to ground

   * Note: because most Arduinos have a built-in LED attached
   to pin 13 on the board the LED is optional.
   */

#include "analogInput.h"
#include "digitalOutput.h"
#include "time.h"

main() {
	AnalogPin potentiometer(A0); // potentiometer object, represent the analog input pin A0
	Pin led(13); // led object, represent the digital output pin 13

	while(true) { // repreat forever
		// get the analog input value and using that like time
		int sensorValueLikeTime = potentiometer.read() * miliseconds;

		//blink the led with speed proportional to sensor reading
		led.turnOn();
		delay(sensorValueLikeTime);
		led.turnOff();
		delay(sensorValueLikeTime);
	}
}
