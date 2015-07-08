/*
   Tone (Melody)

   Plays a melody
   
   circuity:
   * 8-ohm speaker on digital pin 8
   */

#include <Melody.h>
#include <Tone.h>
using namespace zeus;

main() {
	Melody music(1_second); // create a music with periode of 1 second

	// compoud the melody with notes and durations
	music.note(C4, 4);
	music.note(G3, 8);
	music.note(G3, 8);
	music.note(A3, 4);
	music.note(G3, 4);
	music.note(SILENCE, 4);
	music.note(B3, 4);
	music.note(C4, 4);

	music.setPauseBetweenNotes(30); // proportional pause between notes, 30% of the note duration

	Tone speaker(8); // object speaker represents the pin 8 to play tones
	music.play(speaker); // play this melody on speaker
}

	
