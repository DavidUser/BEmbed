#pragma once

#include <utility>
#include <cstdint>
#include <stdexcept>
#include "exceptions/InvalidPinNumber.h"

namespace zeus {
	namespace interfaces {
		using PortType = volatile int8_t;

		class Pin {
		private:
			unsigned number;
			PortType * port; // not allocated, just a hardware register reference
			unsigned portPosition;

		public:
			/* Construction by number of pin
			   habitualy printed on board */
			Pin(const unsigned number);
			/* Construction by port and pin
			   habitualy found on datasheet of Microcontroller */
			Pin(PortType * const port, const unsigned position);
		protected:
			/* Verify if the pin is compatible with the functionality expected */
			virtual bool compatible(const unsigned pin) const noexcept = 0;
			//TODO verify the compatibilite of pin based on port and port position
			/* configure the port and position register based on pin number */
			virtual void configureByNumber(const unsigned number) = 0;
		public:
			void setNumber(const unsigned number);
			unsigned getNumber() const noexcept;
			void setPort(PortType * const port);
			PortType * const getPort() const noexcept;
			void setPortPosition(const unsigned position);
			unsigned getPortPosition() const noexcept;
			/* return integer limits of representable values to write on pin */
			// TODO can return a constexp on derived classes
			virtual std::pair<int, int> getLimits() const = 0;
			int getMinLimit() const noexcept;
			int getMaxLimit() const noexcept;
		};
	}
}
