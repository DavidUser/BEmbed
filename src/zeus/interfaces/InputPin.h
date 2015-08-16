#pragma once

#include "Pin.h"

namespace zeus {
	namespace interfaces {
		class InputPin : zeus::interfaces::Pin {
		public:
			virtual unsigned long long read() const = 0;
		};
	}
}
