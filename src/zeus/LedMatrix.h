namespace zeus {
	class LedMatrix {
	private:
		std::vector<std::vector<std::vector<zeus::Led>>> leds;

	public:
		LedMatrix(std::vector<unsigned> cathodes, std::vector<unsigned> anodes);
		void turnAllOn();
		void turnAllOff();
		std::vector<zeus::Led> operator[](unsigned index);
		LedMatrix(std::vector<unsigned> cathodes, std::vector<unsigned> anodes);
		std::vector<zeus::Led> operator[](unsigned index);
	};
}
