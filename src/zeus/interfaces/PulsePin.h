#pragma once

#include "IOPin.h"
#include "Time.h"

namespace zeus {
	namespace interfaces {
		class PulsePin : public zeus::interfaces::IOPin {
		public:
			virtual void write(zeus::Time width) const = 0;
			virtual zeus::Time read() const = 0;
		};
	}
}
