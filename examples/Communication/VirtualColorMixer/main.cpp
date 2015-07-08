/*
   Virtual Color Mixer

   This example reads three analog sensors (potentiometers are easiest)
   and sends their values serially.
   
   TODO
   The host computer program in this folder will take those three values
   and use them to change the background color of the screen.

   The circuit:
   * potentiometers attached to analog input A0, A1 and A2
   */

#include <Serial.h>
#include <AnalogPin.h>

main() {
	Serial usb; //usb object, represents the USB serial connection
	AnalogPin potRed(A0), potGreen(A1), potBlue(A3); // objects with represent analog redable pins

	while(true) //do this forever
		// output the analog reading via serial
		usb << potRed.read() << ',' // read the analog value of pot red and sends value via serial
			<< potGreen.read() << ',' // read the analog value and send via serial
			<< potBlue.read() << ',' // read the analog value and send via serial
			<< endl; // output a new line
}
