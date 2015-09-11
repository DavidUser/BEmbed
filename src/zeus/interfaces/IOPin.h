#pragma once

#include "InputPin.h"
#include "OutputPin.h"

namespace zeus {
	namespace interfaces {
		class IOPin : public zeus::interfaces::InputPin, zeus::interfaces::OutputPin {
		};
	}
}
