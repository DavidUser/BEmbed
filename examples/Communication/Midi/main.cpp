/*
   MIDI note player

   This example shows how to use the serial transmit pin (pin 1) to send MIDI note data.
   If this circuit is connected to a MIDI synth, it will play
   the notes F#-0 (0x1E) to F#-5(0x5A) in sequence

   The circuit:
   * digital in 1 connected to MIDI jack pin 5
   * MIDI jack pin 2 connected to ground
   * MIDI jakc pin 4 connected to +5V through 220-ohm resistor
   Attach a MIDI cable to the jack, then to a MIDI synth, and play music.
   */

#include <Serial.h>
#include <time.h>
using namespace zeus;

main() {
	Serial midi(31250, CHANNEL_1); // midi object, represent MIDI connection with baund rate of 31250 Hz
	const byte COMMAND = 0x90; // MIDI command to send note data

	midi << Serial::BYTES;
	for (int note = 0x1E; note < 0x5A; ++note) {
		// note command, some note value (note), middle velocity (0x45)
		midi << COMMAND << note << 0x45; // send commands like bytes
		delay(100_milliseconds); // wait 100ms
		// note command, some note value (note), middle velocity (0x45)
		midi << COMMAND << note << 0x00;
		delay(100_milliseconds); // wait 100ms
	}
}

