/*
   Serial Call and Response (handshaking)

   This program sends ASCII A (byte of value 65) on startup
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
		usb << 'A'; // send capital A, this notify the computer a send request
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
	while (true) 	// repeat forever
		usb << Serial::BYTES // instruct usb that integer values are sended like bytes (0 - 255)
			<< firstSensor.read()/4 // send the value of the sensor divided by 4 value between 0 and 255
			<< secondSensor.read()/4 // do the same thing to the second sensor
			<< (button.getState()? 0:255);	// send the button state like 0 to unpushed and 255 to pushed
}

