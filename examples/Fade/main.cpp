/*
   Fade
   This example shows how to fade an LED on pin 9
   using the PWM (Pulse Width Modulation) function
   */

#include <analogOutput.h>

main() {
	PWMPin led(9); // object led repesent the pin 9 with pwm capability
	
	int fadeAmount = 5; // how many points to fade LED by
	// start brightness, repeate forever, increment brightness by the fade amount
	for(int brightness = 0; true; brightness += fadeAmount) {
		led.write(brightness); // set the brightness
		
		//reverse the direction of the fading at the ends of the fade
		if (brightness <= 0 || brightness >= 255) // found minimum or maximum pwm value
			fadeAmount = -fadeAmount; //toogle between increase and decrease
		delay(1_seconds);
	}
}

