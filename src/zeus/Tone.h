namespace zeus {
	class Tone {
	public:
		Tone(unsigned pin);
		void play(unsigned pitch, zeus::Time time);
	};
}
