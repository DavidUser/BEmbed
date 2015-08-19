void zeus::interfaces::Interruption::addUserFunction(const FunctionType function) {
	//TODO some limit of function execution time need be measured and checked
	functionsToEveryEvent.insert(function);
}

void zeus::interfaces::Interruption::addUserFunction(const FunctionType function, const zeus::platforms::PlatformFactory::InterruptionEvent event) try {
	functionsWithSpecificEvent.at(event).insert(function);
} catch (std::out_of_range &&exception) {
	throw exception::InvalidInterruptEvent(event, "not possible add user function: this interruption not support the event argument");
}

void zeus::interfaces::Interruption::execute() const noexcept {
	for (auto function : functionsToEveryEvent)
		function();
	for (auto function : functionsWithSpecificEvent[getCurrentEvent()])
		function();
}
