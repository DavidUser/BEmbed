#pragma once

#include "IOPin.h"
#include <utility>

namespace zeus {
	namespace interfaces {
		class DigitalPin : public zeus::interfaces::IOPin {
		public:
			static const bool HIGH = true;
			static const bool LOW = false;

			virtual void setState(const bool state) = 0;
			virtual bool getState() const = 0;
			virtual void turnHigh() = 0;
			virtual void turnLow() = 0;
			virtual void toogle() = 0;
		};
	}
}
