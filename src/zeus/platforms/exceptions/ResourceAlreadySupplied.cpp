#include "ResourceAlreadySupplied.h"
template <typename Resource>
zeus::platforms::exceptions::ResourceAlreadySupplied<Resource>::ResourceAlreadySupplied(Resource resource) {
	// TODO - implement ResourceAlreadySupplied::ResourceAlreadySupplied
	throw "Not yet implemented";
}
template <typename Resource>
Resource zeus::platforms::exceptions::ResourceAlreadySupplied<Resource>::getExistentResource() {
	// TODO - implement ResourceAlreadySupplied::getExistentResource
	throw "Not yet implemented";
}
template <typename Resource>
std::string zeus::platforms::exceptions::ResourceAlreadySupplied<Resource>::getProblemsOfConcurrentUse() {
	return this->problemsOfConcurrentUse;
}
template <typename Resource>
void zeus::platforms::exceptions::ResourceAlreadySupplied<Resource>::setProblemsOfConcurrentUse(std::string problemsOfConcurrentUse) {
	this->problemsOfConcurrentUse = problemsOfConcurrentUse;
}
