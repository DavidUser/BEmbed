/*
   ReadAnalogVoltage
   Reads an analog input on pin A0, converts it to voltage and prints the result to the serial monitor
   Attach the center pin of potentiometer to pin A0, and the outside pins to +5V and ground
   */

#include <AnalogPin.h>
#include <Serial.h>
#include <time.h>
using namespace zeus;

main() {
	AnalogPin potentiometer(A0); // potentiometer object represent the analog pin A0
	Serial usb; // usb object represent the serial connection, using 9600 hz baund rate default value

	while(true) {
		int sensorValue = potentiometer.read(); // read the analog input
		// convert the analog reading (wich goes from 0 - 1023) to a voltage (0 - 5V)
		float voltage = sensorValue * (5f / 1023f);

		usb << sensorValue << endl; //output the sensor value and create a newline
		delay(1_seconds); //wait 1 second, using user-defined literals (C++11)
	}
}
		
