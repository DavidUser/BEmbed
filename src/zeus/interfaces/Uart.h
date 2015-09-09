#pragma once

namespace zeus {
	namespace interfaces {
		class Uart : zeus::interfaces::Communication {
		public:
			virtual void setBaundRate(unsigned baundRate) = 0;
		};
	}
}
