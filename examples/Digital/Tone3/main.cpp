/*
   Keyboard

   Plays a pitch that changes based on a changing analog input

   circuit:
   * 3 force-sensing resistors from +5V to analgo in A0 through A5
   * 3 10K resistors from analog in A0 through A5 to ground
   * 8-ohm speaker on digital pin 8
   */

#include "analogInput.h"
#include "Tone.h"
#include <map.h>

main() {
	AnalogPin keys[] = { A0, A1, A2 }; // pins of sensors reading
	
	std::map<keys, NOTE> keyToNote { // map keys to notes
		{keys[0], NOTE_A4},
		{keys[1], NOTE_B4},
		{keys[2], NOTE_C3}
	}
	const int THRESHOLD = 10; // minimum reading of the sensors that generates a note

	Tone speaker(8); // object speaker

	while (true) // do this check forever
		for (AnalogPin key : keys) // for each key, using C++11 foreach syntax
			if (key.read() > THRESHOLD) // if value read from sensor is greater than the threshold
				speaker.tone(keyToNote[key], 20_milliseconds); // play the corresponding note by 20ms
}
		

