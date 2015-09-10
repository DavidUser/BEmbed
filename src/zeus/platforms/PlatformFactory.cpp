#include "PlatformFactory.h"

static zeus::platforms::PlatformFactory& zeus::platforms::PlatformFactory::getInstance() {
#ifndef __ZEUS_PLATFORM__
#error "Define a platform name before use Platform Factory"
#else
	static zeus::platforms::__ZEUS_PLATFORM__::PlatformFactory instance;
	return instance;
#endif
}
