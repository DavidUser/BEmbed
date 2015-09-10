#include "NoHardwareSupport.h"

void zeus::platforms::exceptions::NoHardwareSupport::NoHardwareSupport(std::string similarResources) {
	// TODO - implement NoHardwareSupport::NoHardwareSupport
	throw "Not yet implemented";
}

std::string zeus::platforms::exceptions::NoHardwareSupport::getSimilarResources() {
	return this->similarResources;
}

void zeus::platforms::exceptions::NoHardwareSupport::setSimilarResources(std::string similarResources) {
	this->similarResources = similarResources;
}
