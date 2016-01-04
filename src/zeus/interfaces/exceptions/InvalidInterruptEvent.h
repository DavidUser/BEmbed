#pragma once

#include <stdexcept>
#include "../../platforms/PlatformFactory.h"

namespace zeus {
	namespace interfaces {
		namespace exceptions {
			class InvalidInterruptEvent : public std::out_of_range {
				platforms::InterruptionEvent event;

			public:
				InvalidInterruptEvent(platforms::InterruptionEvent event, std::string message = "");
			};
		}
	}
}
