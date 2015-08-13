namespace zeus {
	class PWMPin : zeus::interfaces::PWMPin {
	public:
		PWMPin(unsigned pinNumber);
		static std::vector<zeus::PWMPin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
		void setPulseWidth(Time width);
		Time getPulseWidth();
		void turnOn();
		void turnOff();
		void setMode(PWMMode mode);
		PWMMode getMode();
		std::pair<int, int> getLimits();
		void write(unsigned long long value);
		void setNumber(unsigned number);
		unsigned getNumber();
	public:
		bool compatible(unsigned pin);
		void write(unsigned long long value);
	};
}
