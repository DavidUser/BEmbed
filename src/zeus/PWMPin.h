#pragma once

#include "interfaces/PWMPin.h"
#include "platforms/PlatformFactory.h"
#include <vector>
#include "platforms/exceptions/NoHardwareSupport.h"

namespace zeus {
	class PWMPin {
		std::unique_ptr<zeus::interfaces::PWMPin> pinInstance;
	public:
		PWMPin(unsigned pinNumber);
		static std::vector<zeus::PWMPin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
		inline void setPulseWidth(Time width);
		inline Time getPulseWidth() const;
		inline void turnOn();
		inline void turnOff();
		inline void setMode(PWMMode mode);
		inline PWMMode getMode() const;
		inline std::pair<int, int> getLimits() const;
		inline void write(unsigned long long value);
		inline void setNumber(unsigned number);
		inline unsigned getNumber() const;
	public:
		bool compatible(unsigned pin) const;
	};
}

zeus::PWMPin::PWMPin(unsigned pinNumber) {
	if (compatible(pinNumber))
		pinInstance = PlatformFactory::getInstance().getPWMPin(pinNumber);
	else
		throw platforms::exceptions::NoHardwareSupport("No PWM hardware support on this pin");
}

std::vector<zeus::PWMPin> zeus::PWMPin::getRange(unsigned pinNumberStart, unsigned pinNumberEnd) {
	std::vector<zeus::PWMPin> pinsOnRange;
	for (unsigned i = pinNumberStart; i <= pinNumberEnd; ++i)
		pinsOnRange.emplace_back(i);
	return pinsOnRange;
}

void zeus::PWMPin::setPulseWidth(zeus::Time width) {
	this->pinInstance.setPulseWidth(width);
}

zeus::Time zeus::PWMPin::getPulseWidth() const {
	return this->pinInstance.getPulseWidth();
}

void zeus::PWMPin::turnOn() {
	this->pinInstance.turnOn();
}

void zeus::PWMPin::turnOff() {
	this->pinInstance.turnOff();
}

void zeus::PWMPin::setMode(PWMMode mode) {
	this->pinInstance.setMode(mode);
}

zeus::PWMMode zeus::PWMPin::getMode() const {
	return this->pinInstance.getMode();
}

std::pair<int, int> zeus::PWMPin::getLimits() const {
	return this->pinInstance.getLimits();
}

void zeus::PWMPin::write(unsigned long long value) {
	this->pinInstance.write(value);
}

void zeus::PWMPin::setNumber(unsigned number) {
	this->pinInstance.setNumber(number);
}

unsigned zeus::PWMPin::getNumber() const {
	return this->pinInstance.getNumber();
}

bool zeus::PWMPin::compatible(unsigned pin) const {
	return this->pinInstance.compatible(pin);
}

