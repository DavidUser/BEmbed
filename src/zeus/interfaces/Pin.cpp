#include "Pin.h"
#include "exceptions/InvalidPinNumber.h"
using zeus::interfaces::PortType;

zeus::interfaces::Pin::Pin(const unsigned number) : number(number) {
	if (compatible(number))
		configureByNumber(number);
}

zeus::interfaces::Pin::Pin(PortType * const port, const unsigned position) : port(port), portPosition(position), number(0) {
}

void zeus::interfaces::Pin::setNumber(const unsigned number) {
	if (!compatible(number))
		throw exceptions::InvalidPinNumber(number);
	this->number = number;
}

unsigned zeus::interfaces::Pin::getNumber() const noexcept {
	return this->number;
}


void zeus::interfaces::Pin::setPort(PortType * const port) {
	//TODO verify if it's port reference exist
	if (port == nullptr)
		throw std::invalid_argument("port can't be null");
	this->port = port;
}

PortType * const zeus::interfaces::Pin::getPort() const noexcept {
	return this->port;
}

void zeus::interfaces::Pin::setPortPosition(const unsigned position) {
	//TODO verify if the position argument is on range, variate by platform
	this->portPosition = position;
}

unsigned zeus::interfaces::Pin::getPortPosition() const noexcept {
	return this->portPosition;
}

int zeus::interfaces::Pin::getMinLimit() const noexcept {
	//TODO verify if can return a constexpr
	return getLimits().first;
}

int zeus::interfaces::Pin::getMaxLimit() const noexcept {
	//TODO verify if can return a constexpr
	return getLimits().second;
}
