/*
   Serial Event

   When new serial data arrives, this sketch adds it to a String.
   When a newline is received, the loop prints the string and
   clears it.

   A good test for this is to try it with a GPS receiver
   that sends out NMEA 0183 sentences.
   */

#include <Serial.h>
#include <SignalInterruption.h>
using zeus::Serial;
using zeus::SignalInterruption;
#include <sstream>
using std::stringstream;

stringstream input; // a string to hold incoming data
bool stringComplete;

void serialEvent() {
	char character = usb.get(); // get a byte received from usb
	input << character; // then put it on input string stream
	stringComplete = character == '\n'; // the string is complete when the character received is a newline
}

main() {
	Serial usb; // usb object, represents the USB serial connection

	/* when a character is received on usb the SignalInterruptoin object calls serialEvent() function.
	   It is a signal interruption object so he call a function when a event (of signal) occurs */
	SignalInterruption characterReceive( 
			usb.getSignalCharacterReceived(), // the signal of interruption is get from usb
			serialEvent); // the funciton to be called is serialEvent()

	while(true) { // repreat forever
		if (stringComplete) { // if a newline character was received
			usb << input.str(); // get the string from input stream and put on usb serial stream

			input.str(""); // clear the stream input set your string to ""
			stringComplete = false; // and now the string is't complete
		}
	}
}
