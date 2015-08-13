namespace zeus {
	namespace platforms {
		class PlatformFactory {
		public:
			virtual std::unique_ptr<zeus::interfaces::DigitalPin> getDigitalPin(unsigned number) = 0;
			virtual std::unique_ptr<zeus::interfaces::AnalogPin> getAnalogPin(unsigned number) = 0;
			virtual std::unique_ptr<zeus::interfaces::PWMPin> getPWMPin(unsigned number) = 0;
			virtual std::unique_ptr<zeus::interfaces::PulsePin> getPulsePin(unsigned number) = 0;
			virtual std::unique_ptr<zeus::interfaces::Communication> getSerialCommunication(zeus::platforms::PlatformFactory::CommunicationChannel channel) = 0;
			std::unique_ptr<zeus::platforms::msp430g2553::Timer> getTimer(Timers timerId);
			std::unique_ptr<zeus::interfaces::Interruption> getInterruption(zeus::platforms::PlatformFactory::InterruptionEvent event);
			static zeus::platforms::PlatformFactory& getInstance();
			std::unique_ptr<zeus::platforms::msp430g2553::Timer> getTimer(Timers timerId);

			enum CommunicationChannel {
			};
			enum AnalogResolution {
			};
			enum InterruptionEvent {
			};
			enum Timers {
			};
			enum TimerMode {
			};
		};
	}
}
