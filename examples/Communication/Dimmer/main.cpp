/*
   Dimmer

   Demonstrates the sending data from  the computer to the Arduino board,
   in this case to control the brightness of an LED. The data is sent
   in individual bytes, each of wich ranges from 0 to 255. Arduino
   reads these bytes and uses them to set the brightness of the LED.

   The circuit:
   * LED attached from digital pin 9 to ground
   * Serial connection
   */

#include <Serial.h>
#include <PWMPin.h>
using namespace zeus; //using Serial and PWMPin of namespace zeus


main() {
	Serial usb; // usb object, represents USB serial connection
	PWMPin led(9); // led object, represents the PWM ouput pin 9

	while (true) {
		byte brightness;  // create a variable brightness with one byte of size (value from 0 to 255)
		usb >> brightness; // reads from serial connection the brightness value
		led.write(brightness); // sets the brightness of the led
	}
}
