namespace zeus {
	namespace interfaces {
		class AnalogPin : zeus::interfaces::InputPin {
		public:
			virtual unsigned long long read() = 0;
			virtual void setResolution(zeus::platforms::PlatformFactory::AnalogResolution resolution) = 0;
			virtual Resolution getResolution() = 0;
			virtual std::pair<int, int> getLimits() = 0;
			virtual void setResolution(zeus::platforms::PlatformFactory::AnalogResolution resolution) = 0;
		};
	}
}
