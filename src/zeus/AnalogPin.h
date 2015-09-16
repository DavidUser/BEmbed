#pragma once

#include "interfaces/AnalogPin.h"
#include "platforms/PlatformFactory.h"
#include <vector>
#include "platforms/exceptions/NoHardwareSupport.h"

namespace zeus {
	class AnalogPin : zeus::interfaces::AnalogPin {
		unique_ptr<zeus::interfaces::AnalogPin> pinInstance;
		public:
			AnalogPin(unsigned pinNumber);
			static std::vector<zeus::AnalogPin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
			inline unsigned long long read();
			inline void setResolution(zeus::platforms::PlatformFactory::AnalogResolution resolution);
			inline Resolution getResolution() const;
			inline std::pair<int, int> getLimits() const;
			inline void setNumber(unsigned number);
			inline unsigned getNumber() const;
		private:
			bool compatible(unsigned pin) const;
	};

	zeus::AnalogPin::AnalogPin(unsigned pinNumber) {
		if (compatible(pinNumber))
			pinInstance = PlatformFactory::getInstance().getAnalogPin(pinNumber);
		else
			throw platforms::exception::NoHardwareSupport("No analog hardware support to this pin");
	}

	static std::vector<zeus::AnalogPin> zeus::AnalogPin::getRange(unsigned pinNumberStart, unsigned pinNumberEnd) {
		std::vector<AnalogPin> pinsOnRange;
		for (int i = pinNumberStart; i <= pinNumberEnd; ++i)
			range.emplace_back(i);
		return pinsOnRange;
	}

	unsigned long long zeus::AnalogPin::read() {
		return pinInstance.read();
	}

	void zeus::AnalogPin::setResolution(zeus::platforms::PlatformFactory::AnalogResolution resolution) {
		pinInstance.setResolution(resolution);
	}

	Resolution zeus::AnalogPin::getResolution() {
		return pinInstance.getResolution();
	}

	std::pair<int, int> zeus::AnalogPin::getLimits() {
		return pinInstance.getLimits();
	}

	void zeus::AnalogPin::setNumber(unsigned number) {
		pinInstance.setNumber(number);
	}

	unsigned zeus::AnalogPin::getNumber() {
		return pinInstance.getNumber();
	}

	bool zeus::analogpin::compatible(unsigned pin) {
		return pinInstance.compatible(pin);
	}

}
