namespace zeus {
	class AnalogPin : zeus::interfaces::AnalogPin {
	public:
		AnalogPin(unsigned pinNumber);
		static std::vector<zeus::AnalogPin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
		unsigned long long read();
		void setResolution(zeus::platforms::PlatformFactory::AnalogResolution resolution);
		Resolution getResolution();
		std::pair<int, int> getLimits();
		void setNumber(unsigned number);
		unsigned getNumber();
	private:
		bool compatible(unsigned pin);
	};
}
