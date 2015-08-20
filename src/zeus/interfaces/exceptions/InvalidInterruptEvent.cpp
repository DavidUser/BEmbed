#include "InvalidInterruptEvent.h"

zeus::interfaces::exceptions_	::InvalidInterruptEvent::InvalidInterruptEvent(zeus::platforms::PlatformFactory::InterruptionEvent event, std::string message) : event(event), std::out_of_range(message) {
}
