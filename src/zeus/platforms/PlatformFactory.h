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
				PlatformFactory();
			public:
				// classified resources
				std::unique_ptr<zeus::interfaces::DigitalPin> getDigitalPin(unsigned number) const;
				std::unique_ptr<zeus::interfaces::AnalogPin> getAnalogPin(unsigned number) const;
				std::unique_ptr<zeus::interfaces::PWMPin> getPWMPin(unsigned number) const;
				std::unique_ptr<zeus::interfaces::PulsePin> getPulsePin(unsigned number) const;
				std::unique_ptr<zeus::interfaces::Communication> getSerialCommunication(zeus::platforms::CommunicationChannel channel) const;
				std::unique_ptr<zeus::interfaces::Timer> getTimer(Timers timerId) const;
				std::unique_ptr<zeus::interfaces::Interruption> getInterruption(zeus::platforms::InterruptionEvent event) const;

				// functional resources
				void delay(zeus::Time time);
				
				// Singleton Pattern
				static PlatformFactory & getInstance() {
					static PlatformFactory instance;
					return instance;
				}

			private:
				struct Impl;
				std::shared_ptr<Impl> pimpl;
		};
	}
}
