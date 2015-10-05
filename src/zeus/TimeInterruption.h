#pragma once

#include "interfaces/Timer.h"
#include "interfaces/Interruption"
#include "interfaces/Time.h"

namespace zeus {
	class TimeInterruption {
		public:
			using FunctionType = void (*)();

		private:
			zeus::interfaces::Timer* timer;
			zeus::interfaces::Interruption* interruption;

		public:
			TimeInterruption(zeus::Time time, FunctionType function);
			void addUserFunction(FunctionType function);
	};
}

zeus::TimeInterruption::TimeInterruption(zeus::Time time, FunctionType function) {
	this->timer = PlatformFactory::getInstance().getAvalibleTimer();
	this->interruption = PlatformFactory::getInstance().getInterruptionEvent(this->timer.getInterruptionEvent());
}

void zeus::TimeInterruption::addUserFunction(FunctionType function) {
	this->interruption.addUserFunction(function);
}
