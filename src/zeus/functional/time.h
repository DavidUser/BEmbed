#pragma once

#include "../interfaces/Time.h"
#include "../platforms/PlatformFactory.h"

void delay(const zeus::Time time) {
	zeus::platforms::PlatformFactory::getInstance().delay(time);
}
