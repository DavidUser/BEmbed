/*
   Multiple tone player

   Plays multiple tones on multiple pins in sequence

   ciruit:
   * 3 8-ohm speaker on digital pnis 6, 7 and 8

   plaing tone is a unlock function (this run in parallel execution)
   do serial work need of delay lockings
   */

#include <Tone.h>
#include <time.h>
using namespace zeus;

main() {
	Tone speakers[] = { 6, 7, 8 };

	while (true) { // repreat the play forever
		speakers[0].play(440, 200_milliseconds); // play note by 200ms
		delay(200_milliseconds); // wait 200ms, until the note ends
		speakers[1].play(494, 500_milliseconds); // play note by 500ms
		delay(500_milliseconds); // wait 500ms, until the note ends
		speakers[2].play(523, 300_milliseconds); // play note by 300ms
		delay(300_milliseconds); // wait 300ms, until the note ends
	}
}
