namespace zeus {
	namespace interfaces {
		class Pin {
		private:
			unsigned number;
			PortType& port;
			unsigned portPosition;

		public:
			Pin(unsigned number);
			Pin(PortType& port, unsigned position);
		private:
			virtual bool compatible(unsigned pin) = 0;
		public:
			void setNumber(unsigned number);
			unsigned getNumber();
			void setPort(PortType& port);
			PortType& getPort();
			void setPortPosition(unsigned position);
			unsigned getPortPosition();
			virtual std::pair<int, int> getLimits() = 0;
			int getMinLimit();
			int getMaxLimit();
		};
	}
}
