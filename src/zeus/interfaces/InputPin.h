namespace zeus {
	namespace interfaces {
		class InputPin : zeus::interfaces::Pin {
		public:
			virtual unsigned long long read() = 0;
		};
	}
}
