namespace zeus {
	namespace interfaces {
		class DigitalPin : zeus::interfaces::IOPin {
		public:
			bool HIGH;
			bool LOW;

			virtual void setState(bool state) = 0;
			virtual bool getState() = 0;
			virtual void turnHigh() = 0;
			virtual void turnLow() = 0;
			virtual void toogle() = 0;
			virtual std::pair<int, int> getLimits() = 0;
		};
	}
}
