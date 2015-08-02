/*
   LED bar graph

   Turns on a series of LEDs based on the value of an analog sensor.
   This is a simple way to make a bar graph display. Though this graph
   uses 10 LEDs, you can use any number by changing the LED count
   and the pins in the array.

   This method can be used to control any series of digital outputs that
   depends on an analog input

   The circuit:
   * LEDs from pins 2 through 11 to ground
   * Potentiometer middle to pin A0
   * Potentiometer up to +5V
   * Potentiometer botton to ground
   */

#include <DigitalPin.h>
#include <AnalogPin.h>
#include <map.h>
using namespace zeus;
#include <vector>

main() {
	std::vector<DigitalPin> bar = DigitalPin::getRange(2,11); // get a range of objects that represent digital pins
	AnalogPin potentiometer(A0); // represents the analog input pin A0

	while (true) { // repeat forever
		unsigned ledLevel = map(potentiometer.read(), 0, 1023, 0, bar.size()); // map the analog value to the range of bar of LEDs
		for (unsigned thisLed = 0; thisLed < bar.size(); ++thisLed)
			bar[thisLed].setState(thisLed < ledLevel); // set the state of the led, high when thisLed < ledLevel and low otherwise
	}
}
