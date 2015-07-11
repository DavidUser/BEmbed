/*
   Serial Call and Response (handshaking)

   This program sends a "0,0,0" string on startup
   and repreats that until it gets some data in.
   Then it waits for a byte in the serial port and
   sends three sensor values whenever it gets a byte in.

   The circuit:
   * potentiometers attached to analog inputs 0 and 1
   * pushbutton attached to digital I/O 2

   TODO the data can be better view on computer using the custom program on the same folder
   */

#include <Serial.h>
#include <time.h>
#include <Pin.h>
#include <AnalogPin.h>
using namespace zeus;

main() {
	Serial usb; // usb object, represents the serial USB connection

	//estabilish contatct
	do {
		usb << "0,0,0"; // send a initial string, this notify the computer a send request
		delay(300_milliseconds); // wait 300ms
	} while (!usb.dataReceived()); // repeaty while no data received by usb connection
	//connection estabilished
	char response;
	usb >> response; // read data received
	//TODO you can check if the data recived is the expected

	AnalogPin firstSensor(A0), secondSensor(A2); // that pins represent the analog pins where the pins are connected
	Pin button(2); // that pin represent the digital pin where the button is connected

	// send the sensor values
	// diferently from Arduino example delay to ADC recover is not necessary, it's built-in checked
	while (true) // repeat forever
		usb << firstSensor.read() << ',' 	// send the value of the first sensor
			<< secondSensor.read() << ','	// send the value of the second sensor
			<< (button.getState()? 0:255)	// send the button state like 0 to unpushed and 255 to pushed
			<< endl; 			// send a new line
}

