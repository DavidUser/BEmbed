#include "InvalidPinNumber.h"

zeus::interfaces::exceptions::InvalidPinNumber::InvalidPinNumber(unsigned number) : number(number) {
}

const unsigned& zeus::interfaces::exceptions::InvalidPinNumber::getNumber() {
	return this->number;
}
