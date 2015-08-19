#pragma once

#include "Time.h"
#include "../platforms/PlatformFactory.h"

namespace zeus {
	namespace interfaces {
		class Timer {
		public:
			virtual void configureInterval(const zeus::Time time) = 0;
			virtual void configureMode(const platforms::PlatformFactory::TimerMode mode) = 0;
			virtual void start() = 0;
			virtual void stop() = 0;
			virtual zeus::platforms::PlatformFactory::InterruptionEvent getInterruptionEvent() const = 0;
			virtual constexpr unsigned long long getMaxLimit() const noexcept = 0;
			virtual unsigned long long getCurrent() const = 0;
			virtual static constexpr unsigned long long getClocksBy(const zeus::Time time) noexcept = 0;
		};
	}
}
