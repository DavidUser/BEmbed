namespace zeus {
	class DigitalPin : zeus::interfaces::DigitalPin {
	public:
		DigitalPin(unsigned pinNumber);
		static std::vector<zeus::DigitalPin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
		void setState(bool state);
		bool getState();
		void turnHigh();
		void turnLow();
		void toogle();
		std::pair<int, int> getLimits();
		unsigned long long read();
		void setNumber(unsigned number);
		unsigned getNumber();
		void write(unsigned long long value);
	public:
		bool compatible(unsigned pin);
		void write(unsigned long long value);
	};
}
