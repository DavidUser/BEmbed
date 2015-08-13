namespace zeus {
	class Led {
	private:
		zeus::DigitalPin pin;

	public:
		Led(unsigned pin);
		void turnOn();
		void turnOff();
	};
}
