#pragma once

#include <stdexcept>
#include "../../platforms/PlatformFactory.h"

namespace zeus {
	namespace interfaces {
		namespace exceptions {
			class InvalidInterruptEvent : public std::out_of_range {
				platforms::PlatformFactory::InterruptionEvent event;

			public:
				InvalidInterruptEvent(platforms::PlatformFactory::InterruptionEvent event, std::string message = "");
			};
		}
	}
}
