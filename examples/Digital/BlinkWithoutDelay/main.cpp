/*
   BlinkWithoutDelay

   Turns on and off a light emitting diode (LED) connectded to a digital pin,
   without using the delay() function. This means that other code
   can run at the same time without being interrupted by the LED code.

   The circuit:
   * LED attached from pin 13 to ground.
   * Note: on most Arduinos, there is already an LED on the board
   that's attached to pin 13, so no hardware is needed for this example.
   */

#include <digitalOutput.h>
#include <interruption.h>
#include <Serial.h>

Pin led(13); // led object represent the digital pin 13

// this function make the blink step
void blink() { 	
	led.toggle(); // toggle the state of led, if it's on turn off otherwise if it's off turn on
}

main() {
	/*
	   Create a hardware interruption,
	   an interruption stops the normal working of the microcontroller and run another work,
	   in this case at every 1 second the microcontroller will stop the normal working
	   and call the function blink(), then it will back to you normal working until the next second.
	   */
	TimeInterruption blinkInterruption(1_seconds, blink); // blinkInterruption object represent a hardware interruption

//	OPTIONALY: you can use this methods to change the interruption behavior
//	blinkInterruption.setupPeriode(1_seconds); //set the time periode of execute function to 1 second
//	blinkInterruption.attachFuction(blink); //attach the function blink to be run at interruption

	Serial usb; // usb object represent the serial connection

	while (true) { // do this check forever
		usb << led.getState() << endl; // output the led state and create a new line
		delay(1_seconds); // wait one second
	}
}
		

