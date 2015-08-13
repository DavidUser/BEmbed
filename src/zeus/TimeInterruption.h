namespace zeus {
	class TimeInterruption {
	private:
		zeus::interfaces::Timer* timer;
		zeus::interfaces::Interruption interruption;

	public:
		TimeInterruption(zeus::Time time, void (* function)());
		void addUserFunction(void (* function)());
		TimeInterruption(zeus::Time time, void (* function)());
		void addUserFunction(void (* function)());
	};
}
