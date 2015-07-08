/*
   Graph
   
   A simple example of communication from the board to the computer:
   the value of analog input 0 is sent out the serial port. We call this "serial"
   communication because the connection appers to both the board and the computer
   as a serial port, even though it may actually use a USB cable.
   Bytes are sent one after other (serially) from  the Arduino to the computer.

   TODO this feature need be implemented, in various languages but at principle in C++
   You can use the program in this folder that reads serial port and generate
   a realtime graph of the reading released.

   The circuit:
   * Any analog sensor is attached to analog in pin 0.
   */

#include <Serial.h>
#include <AnalogPin.h>
#include <time.h>
using namespace zeus; // using Serial, AnalogPin and delay from namespace zeus

main() {
	Serial usb; // usb object, represents the USB serial connection
	AnalogPin sensor(A0); // sensor object, represents the analog readable pin A0

	usb << sensor.read(); // read sensor value and output this via serial
	delay(2_milliseconds); // wait 2ms
}
