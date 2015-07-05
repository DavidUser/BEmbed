/*
   AnalogReadSerial
   Reads an analog input on pin 0, prints the result on the serial monitor
   Attach the center pin of potentiometer to pin A0, and the outside pins to +5V and ground
   */

#include <analogInput.h>

main() {
	AnalogPin potentiometer(A0); // potentiometer object represent the analog pin A0
	Serial usb; // usb object represent the serial connection, using 9600 hz baund rate default value

	while(true) {
		int sensorValue = potentiometer.read(); // read the analog input

		usb << sensorValue << endl; //output the sensor value and create a newline
		delay(1_seconds); //wait 1 second, using user-defined literals (C++11)
	}
}
		
