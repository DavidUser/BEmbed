#pragma once

#include "InputPin.h"
#include "../platforms/PlatformFactory.h"

namespace zeus {
	namespace interfaces {
		class AnalogPin : public zeus::interfaces::InputPin {
		public:
			virtual void setResolution(zeus::platforms::PlatformFactory::AnalogResolution resolution) = 0;
			virtual Resolution getResolution() const = 0;
		};
	}
}
