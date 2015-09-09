#include "InvalidPinNumber.h"

zeus::interfaces::exceptions::InvalidPinNumber::InvalidPinNumber(unsigned number) : number(number), std::out_of_range("invalid pin number"){
}

const unsigned& zeus::interfaces::exceptions::InvalidPinNumber::getNumber() const {
	return this->number;
}
