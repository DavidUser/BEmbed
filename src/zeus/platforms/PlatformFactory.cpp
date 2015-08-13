#include "PlatformFactory.h"

std::unique_ptr<zeus::platforms::msp430g2553::Timer> zeus::platforms::PlatformFactory::getTimer(Timers timerId, Timers timerId) {
	// TODO - implement PlatformFactory::getTimer
	throw "Not yet implemented";
}

std::unique_ptr<zeus::interfaces::Interruption> zeus::platforms::PlatformFactory::getInterruption(zeus::platforms::PlatformFactory::InterruptionEvent event) {
	// TODO - implement PlatformFactory::getInterruption
	throw "Not yet implemented";
}

static zeus::platforms::PlatformFactory& zeus::platforms::PlatformFactory::getInstance() {
	// TODO - implement PlatformFactory::getInstance
	throw "Not yet implemented";
}
