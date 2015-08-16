#pragma once

#include "InputPin.h"

namespace zeus {
	namespace interfaces {
		class AnalogPin : zeus::interfaces::InputPin {
		public:
			virtual void setResolution(zeus::platforms::PlatformFactory::AnalogResolution resolution) = 0;
			virtual Resolution getResolution() const = 0;
			virtual std::pair<int, int> getLimits() const = 0;
		};
	}
}
