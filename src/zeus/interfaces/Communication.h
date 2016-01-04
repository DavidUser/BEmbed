#pragma once

#include <cinttypes>
#include "../platforms/PlatformFactory.h"

namespace zeus {
	namespace interfaces {
		using Byte = std::uint8_t;
		class Communication {
		public:
			virtual void send(Byte byte) = 0;
			virtual Byte receive() = 0;
			virtual zeus::platforms::InterruptionEvent getReceiveInterruption() = 0;
			virtual zeus::platforms::InterruptionEvent getSendInterruption() = 0;
		};
	}
}
