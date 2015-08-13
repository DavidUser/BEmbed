namespace zeus {
	namespace interfaces {
		class PWMPin : zeus::interfaces::OutputPin {
		public:
			virtual void setPulseWidth(Time width) = 0;
			virtual Time getPulseWidth() = 0;
			virtual void turnOn() = 0;
			virtual void turnOff() = 0;
			virtual void setMode(PWMMode mode) = 0;
			virtual PWMMode getMode() = 0;
			virtual std::pair<int, int> getLimits() = 0;
		};
	}
}
