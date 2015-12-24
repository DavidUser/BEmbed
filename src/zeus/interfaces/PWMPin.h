#pragma once

#include "OutputPin.h"
#include "Time.h"
#include "../platforms/PlatformFactoryEnums.h"

namespace zeus {
	namespace interfaces {
		using PWMMode = zeus::platforms::PlatformFactory::PWMMode;
		class PWMPin : public zeus::interfaces::OutputPin {
		public:
			virtual void setPulseWidth(Time width) = 0;
			virtual Time getPulseWidth() const = 0;
			virtual void turnOn() = 0;
			virtual void turnOff() = 0;
			virtual void setMode(PWMMode mode) = 0;
			virtual PWMMode getMode() const = 0;
			virtual std::pair<int, int> getLimits() const = 0;
		};
	}
}
