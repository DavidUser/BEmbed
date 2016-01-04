#pragma once

namespace zeus {
	namespace platforms {
		enum class CommunicationChannel;
		enum class AnalogResolution;
		enum class InterruptionEvent;
		enum class Timers;
		enum class TimerMode;
		enum class PWMMode;
	}
}

#include <functional>
#include <type_traits>

#define HASH_REDEFINITION(ENUM) 				\
								\
namespace std { 						\
	template<>						\
		struct hash<ENUM> {		\
			size_t operator()(const ENUM & e) const {	\
				return hash< underlying_type<ENUM>::type >()(static_cast< underlying_type<ENUM>::type >(e));	\
			}					\
		};						\
}

HASH_REDEFINITION(zeus::platforms::InterruptionEvent)
