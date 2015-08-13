namespace zeus {
	namespace interfaces {
		class PulsePin : zeus::interfaces::IOPin {
		public:
			virtual void write(unsigned long long widthTime) = 0;
			virtual unsigned long long long read() = 0;
			virtual std::pair<int, int> getLimits() = 0;
			virtual void write(unsigned long long widthTime) = 0;
		};
	}
}
