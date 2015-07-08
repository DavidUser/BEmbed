/*
   Debounce 

   Each time the input pin goes from LOW to HIGH (e.g. because of a push-button 
   press), the outrput pin is toogled from LOW to HIGH or HIGH to LOW.
   There's a minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

   The circuit:
   * LED attached from pin 13 to ground
   * pushbutton attached to pin 2 from +5V
   * 10K resistor attached to pin 2  from ground

   * Note: on most Arduinos there is already an LED on the board
   attached to pin 13
   */

#include <Pin.h>
#include <SignalInterruption.h>
#include <time.h>
using namespace zeus;

Pin button(2); // object button represent the digital pin 2
Pin led(13); // object led represent the digital pin 13

long debounceDelay = 50;

// function called when a pin change your state
void buttonStateToLED() {
	/* static variable, initalized with zero just in the first execution of this function, 
	   future executions of this function will not initialize this variable and 
	   the last value will continue avalible.
	   */
	static long lastToggleTime = 0; 

	if (lastToggleTime && //past toogle ocurred (time greatest than 0)
			currentTime() - lastToggleTime > debounceDelay) { //the button was pressed at a minimum debounceDelay interval
		led.toggle(); // toggle the led state
	}
	lastToggleTime = currentTime(); // reset the last toggle time to the current time
}

main() {
	/* An interruption stop the normal working of microcontroller and run another work,
	   in this case every change on pin represented by button will stop the normal working of microcontroller
	   and call the buttonStateToLED() function, then it'll return to the normal work until the next change
	   on pin represented by button
	   */
	SignalInterruption buttonPress(TOGGLE, button, buttonStateToLED); // buttonPress object represent a hardware interruption detecting toggle on pin button and call the buttonStateToLED() function

	/* TODO a risign debounce detection can be buit-in implemented to offer a simplest implementation,
	   at this way buttonStateToLED() function can continue like the presented in the Button example,
	   only with a led.toggle() call
	   */
	// SignalInterruption buttonPress(RISING_DEBOUNCE, debounceDelay, button, buttonStateToLED);
}
