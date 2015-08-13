namespace zeus {
	namespace interfaces {
		class Timer {
		public:
			void configureInterval(zeus::Time time);
			void configureMode(TimerMode mode);
			void start();
			void stop();
			zeus::platforms::PlatformFactory::InterruptionEvent getInterruptionEvent();
			unsigned long long getMaxLimit();
			unsigned long long getCurrent();
			unsigned long long getClocksBy(zeus::Time time);
		};
	}
}
