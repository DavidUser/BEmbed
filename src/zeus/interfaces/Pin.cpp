#include "Pin.h"

zeus::interfaces::Pin::Pin(unsigned number) {
	// TODO - implement Pin::Pin
	throw "Not yet implemented";
}

zeus::interfaces::Pin::Pin(PortType& port, unsigned position) {
	// TODO - implement Pin::Pin
	throw "Not yet implemented";
}

void zeus::interfaces::Pin::setNumber(unsigned number) {
	this->number = number;
}

unsigned zeus::interfaces::Pin::getNumber() {
	return this->number;
}

void zeus::interfaces::Pin::setPort(PortType& port) {
	this->port = port;
}

PortType& zeus::interfaces::Pin::getPort() {
	return this->port;
}

void zeus::interfaces::Pin::setPortPosition(unsigned position) {
	this->portPosition = position;
}

unsigned zeus::interfaces::Pin::getPortPosition() {
	return this->portPosition;
}

int zeus::interfaces::Pin::getMinLimit() {
	// TODO - implement Pin::getMinLimit
	throw "Not yet implemented";
}

int zeus::interfaces::Pin::getMaxLimit() {
	// TODO - implement Pin::getMaxLimit
	throw "Not yet implemented";
}
