#pragma once

#include "interfaces/DigitalPin.h"
#include "platforms/PlatformFactory.h"
#include <vector>
#include "platforms/exceptions/NoHardwareSupport.h"

namespace zeus {
	//Facade to Digital Pin, this decouples DigitalPin object utilization from platform future modifications:

	class DigitalPin : zeus::interfaces::DigitalPin {
		std::unique_ptr<zeus::interfaces::DigitalPin> pinInstance;
		public:
			DigitalPin(unsigned pinNumber);
			static std::vector<zeus::DigitalPin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
			inline void setState(bool state);
			inline bool getState() const;
			inline void turnHigh();
			inline void turnLow();
			inline void toogle();
			inline std::pair<int, int> getLimits() const;
			inline unsigned long long read();
			inline void setNumber(unsigned number);
			inline unsigned getNumber() const;
			inline void write(unsigned long long value);
		private:
			bool compatible(unsigned pin) const;
	};

	zeus::DigitalPin::DigitalPin(unsigned pinNumber) {
		if (compatible(pinNumber))
			pinInstance = PlatformFactory::getInstance().getDigitalPin(pinNumber);
		else
			throw platforms::exceptions::NoHardwareSupport("No digital hardware support on this pin");
	}

	static std::vector<zeus::DigitalPin> zeus::DigitalPin::getRange(unsigned pinNumberStart, unsigned pinNumberEnd) {
		std::vector<zeus::DigitalPin> pinsOnRange;
		for (unsigned i = pinNumberStart; i <= pinNumberEnd; ++i)
			pinsOnRange.emplace_back(i);
		return pinsOnRange;
	}

	void zeus::DigitalPin::setState(bool state) {
		pinInstance->setState(state);
	}

	bool zeus::DigitalPin::getState() {
		return pinInstance->getState();
	}

	void zeus::DigitalPin::turnHigh() {
		pinInstance->turnHigh();
	}

	void zeus::DigitalPin::turnLow() {
		pinInstance->turnLow();
	}

	void zeus::DigitalPin::toogle() {
		pinInstance->toogle();
	}

	std::pair<int, int> zeus::DigitalPin::getLimits() {
		return pinInstance->getLimits();
	}

	unsigned long long zeus::DigitalPin::read() {
		return pinInstance->read();
	}

	void zeus::DigitalPin::setNumber(unsigned number) {
		pinInstance->setNumber(number);
	}

	unsigned zeus::DigitalPin::getNumber() {
		return pinInstance->getNumber();
	}

	void zeus::DigitalPin::write(unsigned long long value) {
		pinInstance->write(value);
	}

	bool zeus::DigitalPin::compatible(unsigned pin) {
		return pinInstance->compatible(pin);
	}

}
