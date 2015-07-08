/*
   ASCII table

   Prints out byte values in all possible formats:
   * as raw binary values
   * as ASCII-encoded decimal, hex, octal, and binary values

   For more on ASCII, see http://www.asciitable.com and http://en.wikipedia.org/wiki/ASCII

   The circuit: No external hardware needed.
   */

#include <Serial.h>
using zeus::Serial; // using Serial of namespace zeus

main() {
	Serial usb; // usb object, represents the USB serial connection

	usb << "ASCII Table ~ Character Map" << endl; // output via serial

	for (char ch = 33; ch < 127; ++ch) // list the character from decimal 33 value to 127
		usb << ch // output ascii symbol (character)
			<< ", dec: " << Serial::dec << static_cast<int>(ch) // output ascii value decimal
			<< ", hex: " << Serial::hex << static_cast<int>(ch) // output ascii value hexadecimal
			<< ", oct: " << Serial::oct << static_cast<int>(ch) // output ascii value octal
			<< ", bin: " << Serial::bin << static_cast<int>(ch) // output ascii value binary
			<< endl; // create a newline
	while(true); // lock the program, doing nothing forever
}
