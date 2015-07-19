/*
   Row-Column Scanning an 8x8 LED matrix with X-Y input

   This example controls an 8x8 LED matrix using two analog inputs

   TODO simplify the circuit
   The circuit:
    The Matrix:
    * Digital pins 2 through 13,
    * analog pins 2 through 5 used as digital 16 through 19
    The Potentiometers:
    * center pins are attached to analog pins 0 and 1, respectively
    * side pins attached to +5V and ground, respectively.

   */

#include <LEDMatrix.h>
#include <AnalogPin.h>
using namespace zeus;

main() {
	// represent the LED matrix component
	LEDMatrix matrix( 
			{9, 14, 8, 12, 1, 7, 2, 5},  // cathodes pins
			{13, 3, 4, 10, 6, 11, 15, 16} // anodes pins
			);
	// potentiometers, represent the analog input pins A0 and A1
	AnalogPin xPotentiometer(A0), yPotentiometer(A1); 

	while (true) { // repeat forever
		// map potentiometer readings on cordinates
		unsigned x = map(xPotentiometer.read(), 0, 1023, 0, 7),
			 y = map(yPotentiometer.read(), 0, 1023, 0, 7);
		matrix.turnAllOff(); // turn off all leds of matrix, internaly optimized
		matrix[x][y].turnOn(); // turn on the led on (x,y) position
	}
}
