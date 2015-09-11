#pragma once

namespace zeus {
	namespace interfaces {
		class I2c : public zeus::interfaces::Communication {
		public:
			virtual void connect(unsigned address, Mode mode) = 0;

			enum Mode {
				MASTER, SLAVE
			};
		};
	}
}
