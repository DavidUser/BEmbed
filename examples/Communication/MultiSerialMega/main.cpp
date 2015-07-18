/*
   Mega multiple serial

   Receives from the main serial port, sents to the others.
   Receives from serial port 1 (channel 1), sends to the main serial (channel 0)

   This examplesd works on the Arduino Mega

   The circuit:
   * Any serial device attached to Serial port 1
   * Serial monitor open on Serial port 0
   */

#include <Serial.h>
using zeus::Serial;
#include <SignalInterruption.h>
using zeus::SignalInterruption;

main() {
	const int DEFAULT_BAUND_RATE = 9600; // the default baund rate
	Serial usb(DEFAULT_BAUND_RATE, CHANNEL_0); // usb object, represent the serial connection using CHANNEL_0 (USB connector)
	Serial serial1(DEFAULT_BAUND_RATE, CHANNEL_1); // serial1 object, represent the serial connection to device attached on serial port 1

	// this signal trigger a call to a function when a character is receive on usb
	// transmit via serial1 the characters received on usb
	SignalInterruption usbReceive(usb.getSignalReceiveByte(),
			// C++11 lambda function, function called when usb receive some character
			[&usb, &serial1]() {
				serial1 << usb.read();
			}
			);

	// this signal trigger a call to a function when a character is receive on serial1
	// transmit via usb the characters received on serial1
	SignalInterruption serial1Receive(serial1.getSignalReceiveByte(),
			// C++11 lambda function, function called when serial1 receive some character
			[&serial1, &usb]() {
				usb << serial1.read();
			}
			);
}
