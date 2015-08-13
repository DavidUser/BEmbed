#include "Interruption.h"

std::list<zeus::platforms::PlatformFactory::InterruptionEvent> zeus::interfaces::Interruption::getActivations() {
	// TODO - implement Interruption::getActivations
	throw "Not yet implemented";
}

void zeus::interfaces::Interruption::addUserFunction(void(* function)()) {
	// TODO - implement Interruption::addUserFunction
	throw "Not yet implemented";
}

void zeus::interfaces::Interruption::addUserFunction(void(* function)(), zeus::platforms::PlatformFactory::InterruptionEvent event) {
	// TODO - implement Interruption::addUserFunction
	throw "Not yet implemented";
}

void zeus::interfaces::Interruption::execute() {
	// TODO - implement Interruption::execute
	throw "Not yet implemented";
}
