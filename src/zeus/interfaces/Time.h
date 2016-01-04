#pragma once

//TODO include microseconds, it's present on Arduino
//TODO Can include minute, hour, day and another time measures inclusive clocks can be very useful

namespace zeus {
	using Time = unsigned long long;

	constexpr Time millisecond = 1;
	constexpr Time second = 1000 * millisecond;
}

constexpr zeus::Time operator"" _miliseconds(const zeus::Time miliseconds) {
	return miliseconds * zeus::millisecond;
}

constexpr zeus::Time operator"" _seconds(const zeus::Time seconds) {
	return seconds * zeus::second;
}
