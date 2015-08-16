#pragma once

#include "Pin.h"

namespace zeus {
	namespace interfaces {
		class OutputPin : zeus::interfaces::Pin {
		public:
			virtual void write(unsigned long long value) const = 0;
		};
	}
}
