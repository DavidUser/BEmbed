namespace zeus {
	class Melody {
	private:
		std::list<std::pair<unsigned, unsigned>> notes;

	public:
		Melody(zeus::Time periode);
		void note(unsigned pitch, unsigned duration);
		void setPauseBetweenNotes(unsigned pausePercentage);
		void play(zeus::Tone& tone);
	};
}
