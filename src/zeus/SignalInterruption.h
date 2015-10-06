#pragma once

#include "platforms/PlatformFactory.h"
#include "platforms/exceptions/NoHardwareSupport.h"
#include "interfaces/Interruption.h"
#include "DigitalPin.h"

namespace zeus {
	class SignalInterruption {
		public:
			using FunctionType = void (*)();

			enum SignalEvent {
				TOGGLE, RISING, FALLING
			};

		private:
			zeus::platforms::PlatformFactory::InterruptionEvent event;
			zeus::interfaces::Interruption interruption;
			zeus::DigitalPin & pin;

		public:
			SignalInterruption(SignalEvent event, zeus::DigitalPin& pin, FunctionType function);
			SignalInterruption(zeus::platforms::PlatformFactory::InterruptionEvent event, FunctionType function);

		private:
			bool haveHardwareEventDetection(); //TODO this info need be gived by Platform
			zeus::platforms::PlatformFactory::InterruptionEvent getHardwareEvent(); //TODO this info need be gived by Platform
	};
}

zeus::SignalInterruption::SignalInterruption(zeus::SignalInterruption::SignalEvent event,
	zeus::DigitalPin & pin, zeus::SignalInterruption::FunctionType function) : event(event), pin(pin) {
	if (haveHardwareEventDetection())
		auto hardwareEvent = getHardwareEvent();
		this->interruption = PlatformFactory::getInstance().getInterruptionEvent(hardwareEvent);
		this->interruption.addUserFunction(function, hardwareEvent);
	else
		new throw zeus::platforms::exceptions::NoHardwareSupport("No hardware interruption support");
}

zeus::SignalInterruption::SignalInterruption(zeus::platforms::PlatformFactory::InterruptionEvent event, FunctionType function) : event(event) {
	this->interruption = PlatformFactory::getInstance().getInterruptionEvent(event);
	this->interruption.addUserFunction(function);
}
