#pragma once

#include "../interfaces/DigitalPin.h"
#include "../interfaces/AnalogPin.h"
#include "../interfaces/PWMPin.h"
#include "../interfaces/PulsePin.h"
#include "../interfaces/Communication.h"
#include "../interfaces/Timer.h"
#include "../interfaces/Interruption.h"
#include "PlatformEnums.h"
#include <memory>

namespace zeus {
	namespace platforms {
		class PlatformFactory {
			public:
				PlatformFactory() = default;

				std::unique_ptr<zeus::interfaces::DigitalPin> getDigitalPin(unsigned number);
				std::unique_ptr<zeus::interfaces::AnalogPin> getAnalogPin(unsigned number);
				std::unique_ptr<zeus::interfaces::PWMPin> getPWMPin(unsigned number);
				std::unique_ptr<zeus::interfaces::PulsePin> getPulsePin(unsigned number);
				std::unique_ptr<zeus::interfaces::Communication> getSerialCommunication(zeus::platforms::PlatformFactory::CommunicationChannel channel);
				std::unique_ptr<zeus::interfaces::Timer> getTimer(Timers timerId);
				std::unique_ptr<zeus::interfaces::Interruption> getInterruption(zeus::platforms::PlatformFactory::InterruptionEvent event);
		};
	}
}
