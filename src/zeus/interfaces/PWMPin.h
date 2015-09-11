#pragma once

#include "OutputPin.h"
#include "Time.h"

namespace zeus {
	namespace interfaces {
		class PWMPin : public zeus::interfaces::OutputPin {
		public:
			virtual void setPulseWidth(Time width) = 0;
			virtual Time getPulseWidth() const = 0;
			virtual void turnOn() = 0;
			virtual void turnOff() = 0;
			virtual void setMode(PWMMode mode) = 0;
			virtual PWMMode getMode() const = 0;
			virtual const std::pair<int, int> & getLimits() const = 0;
		};
	}
}
