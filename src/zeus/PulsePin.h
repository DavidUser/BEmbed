namespace zeus {
	class PulsePin : zeus::interfaces::PulsePin {
	public:
		PulsePin(unsigned pinNumber);
		static std::vector<zeus::PulsePin> getRange(unsigned pinNumberStart, unsigned pinNumberEnd);
		void write(unsigned long long widthTime);
		unsigned long long read();
		std::pair<int, int> getLimits();
		void setNumber(unsigned number);
		unsigned getNumber();
	public:
		bool compatible(unsigned pin);
		void write(unsigned long long widthTime);
	};
}
