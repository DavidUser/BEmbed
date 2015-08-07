/*
   Calibration

   Demonstrates one technique for calibration sensor input.
   The sensor reading during the first five seconds of the sketch
   execution define the minimum and maximum of expected values
   attached to the sensor pin.

   The sensor minimum and maximum initial values may seem backwards.
   Initially, you set the minimum high and listen for anything
   lower, saving it as the new minimum. Likewise, you set the
   maximum low and listen for anything higher as the new maximum.

   The circuit:
   * Analog sensor (potentiometer will do) attached to analog input A0
   * LED attached from digital pin 9 to ground
   */

#include <AnalogPin.h>
#include <PWMPin.h>
#include <map.h>
using namespace zeus;

main() {
	AnalogPin sensor(A0);
	PWMPin led(9);

	led.write(led.getMaxLimit());

	// calibrate during the first five seconds
	unsigned int sensorMax = led.getMinLimit(),
		     sensorMin = led.getMaxLimit();
	while (currentTime() < 5_seconds) {
		auto sensorValue = sensor.read(); // read sensor value, using C++03 auto type detection

		if (sensorValue > sensorMax)
			sensorMax = sensorValue; // record the maximum sensor value
		if (sensorValue < sensorMin)
			sensorMin = sensorValue; // record the minimum sensor value
	}

	while (true) { // repeat forever
		// read sensor and maps this value to led values range, maps constraint values too
		unsigned int sensorValueToLED = map(sensor.read(), sensor.getLimits(), led.getLimits());

		led.write(sensorValueToLED); // set the brightness of the led proportinaly with sensor reading
	}
}
