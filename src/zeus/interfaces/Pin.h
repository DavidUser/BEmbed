#pragma once

#include <utility>
#include <stdexcept>
#include "exceptions/InvalidPinNumber.h"

namespace zeus {
	namespace interfaces {

		class Pin {
		private:
			unsigned number;

		public:
			/* Construction by number of pin
			   habitualy printed on board */
			Pin(const unsigned number);
			/* Verify if the pin is compatible with the functionality expected */
			virtual bool compatible(const unsigned pin) const noexcept = 0;
			//TODO verify the compatibilite of pin based on port and port position

			void setNumber(const unsigned number);
			unsigned getNumber() const noexcept;
			/* return integer limits of representable values to write on pin */
			// TODO can return a constexp on derived classes
			virtual std::pair<int, int> getLimits() const = 0;
			int getMinLimit() const noexcept;
			int getMaxLimit() const noexcept;
		};
	}
}
