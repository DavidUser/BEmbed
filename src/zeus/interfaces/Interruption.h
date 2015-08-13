namespace zeus {
	namespace interfaces {
		class Interruption {
		public:
			std::list<zeus::platforms::PlatformFactory::InterruptionEvent> getActivations();
			void addUserFunction(void(* function)());
			void addUserFunction(void(* function)(), zeus::platforms::PlatformFactory::InterruptionEvent event);
			void execute();
		};
	}
}
