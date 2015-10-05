#pragma once

#include "interfaces/PulsePin.h"
#include <vector>
#include "platforms/exception/NoHardwareSupport.h"

namespace zeus {
	class PulsePin {
	public:
		PulsePin(unsigned pinNumber);
		static std::vector<zeus::PulsePin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
		void write(unsigned long long widthTime) const;
		unsigned long long read() const;
		std::pair<int, int> getLimits() const;
		void setNumber(unsigned number);
		unsigned getNumber() const;
	private:
		bool compatible(unsigned pin) const;
	};

	zeus::PulsePin::PulsePin(unsigned pinNumber) {
		if (compatible(pinNumber))
			pinInstance = PlatformFactory::getInstance().getPulsePin(pinNumber);
		else
			throw platforms::exception::NoHardwareSupport("No pulse hardware support to this pin");
	}

	static std::vector<zeus::PulsePin> zeus::PulsePin::getRange(unsigned pinNumberStart, unsigned pinNumberEnd) {
		std::vector<PulsePin> pinsOnRange;
		for (unsigned i = pinNumberStart; i <= pinNumberEnd; ++i)
			pinsOnRange.emplace_back(i);
		return pinsOnRange;
	}

	void zeus::PulsePin::write(unsigned long long widthTime) const {
		pinInstance.write(widthTime);
	}

	unsigned long long zeus::PulsePin::read() const {
		return pinInstance.read();
	}

	std::pair<int, int> zeus::PulsePin::getLimits() const {
		return pinInstance.getLimits();
	}

	void zeus::PulsePin::setNumber(unsigned number) {
		pinInstance.setNumber(number);
	}

	unsigned zeus::PulsePin::getNumber() const {
		return pinInstance.getNumber();
	}

	bool zeus::PulsePin::compatible(unsigned pin) const {
		return pinInstance.compatible(pin);
	}
}
