#include "PlatformFactory.h"

static zeus::platforms::PlatformFactory& zeus::platforms::PlatformFactory::getInstance() {
	//TODO verify avalible hardware
	static PlatformFactory instance;
	return instance;
}
