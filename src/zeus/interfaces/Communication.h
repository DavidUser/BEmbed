namespace zeus {
	namespace interfaces {
		class Communication {
		public:
			virtual void send(Byte byte) = 0;
			virtual Byte receive() = 0;
			virtual zeus::platforms::PlatformFactory::InterruptionEvent getReceiveInterruption() = 0;
			virtual zeus::platforms::PlatformFactory::InterruptionEvent getSendInterruption() = 0;
		};
	}
}
