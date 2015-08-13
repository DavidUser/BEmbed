namespace zeus {
	class SignalInterruption {
	private:
		zeus::platforms::PlatformFactory::InterruptionEvent event;
		zeus::interfaces::Interruption interruption;

	public:
		SignalInterruption(SignalEvent event, zeus::DigitalPin& pin, void(* function)());
		SignalInterruption(zeus::platforms::PlatformFactory::InterruptionEvent event, void(* function)());
		SignalInterruption(SignalEvent event, zeus::DigitalPin& pin, void(* function)());

		enum SignalEvent {
			TOGGLE, RISING, FALLING
		};
	};
}
