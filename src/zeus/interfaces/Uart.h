#pragma once

namespace zeus {
	namespace interfaces {
		class Uart : public zeus::interfaces::Communication {
		public:
			virtual void setBaundRate(unsigned baundRate) = 0;
		};
	}
}
