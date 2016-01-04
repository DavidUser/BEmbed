#pragma once

#include "InputPin.h"
#include "../platforms/PlatformEnums.h"

namespace zeus {
	namespace interfaces {
		using Resolution = zeus::platforms::AnalogResolution;
		class AnalogPin : public zeus::interfaces::InputPin {
		public:
			virtual void setResolution(Resolution resolution) = 0;
			virtual Resolution getResolution() const = 0;
		};
	}
}
