/*
   Fading
   
   This example shows how to fade an LED using the pwm writing

   The circuit:
   * LED attached from digital pin 9 to ground
   */

#include <PWMPin.h>
#include <time.h>
using namespace zeus;

main() {
	PWMPin led(9); // LED connected to digital pin 9

	while (true) { // repeat forever
		// increasing brightness
		for (unsigned fadeValue = led.getMinLimit(); fadeValue <= led.getMaxLimit(); fadeValue += 5)
			led.write(fadeValue), delay(30_milliseconds); // set led brigthness and wait 30ms
		// decreasing brigthness
		for (unsigned fadeValue = led.getMaxLimit(); fadeValue >= led.getMinLimit(); fadeValue -= 5)
			led.write(fadeValue), delay(30_milliseconds); // set led brigthness and wait 30ms
	}
}
	
