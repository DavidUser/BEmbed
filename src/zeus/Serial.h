namespace zeus {
	class Serial : zeus::StreamCommunication {
	public:
		Serial(unsigned baundrate = 9600, unsigned unity = 0);
		InterruptionEvent getSignalSerialCharacterReceived();
		zeus::platforms::PlatformFactory::InterruptionEvent getSignalSerialCharacterSended();
	};
}
