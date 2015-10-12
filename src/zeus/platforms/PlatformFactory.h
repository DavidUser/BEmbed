#pragma once

#include "../interfaces/DigitalPin.h"
#include "../interfaces/AnalogPin.h"
#include "../interfaces/PWMPin.h"
#include "../interfaces/PulsePin.h"
#include "../interfaces/Communication.h"
#include "../interfaces/Timer.h"
#include "../interfaces/Interruption.h"
#include <memory>
#include <map>

namespace zeus {
	namespace platforms {
		class PlatformFactory;

		// TODO define unique resource specialization to management of instace creation
		template <typename Resource>
		class UniqueResource : public std::unique_ptr<Resource> {
			private:
				PlatformFactory &owner;
			public:
				UniqueResource(PlatformFactory &owner, Resource *resource) : owner(owner) resource(resource);
				~UniqueResource();
		};
					

		class PlatformFactory {
			template <typename T>
				friend UniqueResource;
			public:
				enum class CommunicationChannel;
				enum class AnalogResolution;
				enum class InterruptionEvent;
				enum class Timers;
				enum class TimerMode;

			private:
				std::map<Timers, std::unique_ptr<zeus::interface::Timer>> onUseTimers;

			private:
				PlatformFactory() = default;
			public:
				virtual std::unique_ptr<zeus::interfaces::DigitalPin> getDigitalPin(unsigned number) = 0;
				virtual std::unique_ptr<zeus::interfaces::AnalogPin> getAnalogPin(unsigned number) = 0;
				virtual std::unique_ptr<zeus::interfaces::PWMPin> getPWMPin(unsigned number) = 0;
				virtual std::unique_ptr<zeus::interfaces::PulsePin> getPulsePin(unsigned number) = 0;
				virtual std::unique_ptr<zeus::interfaces::Communication> getSerialCommunication(zeus::platforms::PlatformFactory::CommunicationChannel channel) = 0;
				virtual std::unique_ptr<zeus::interfaces::Timer> getTimer(Timers timerId) = 0;
				virtual std::unique_ptr<zeus::interfaces::Interruption> getInterruption(zeus::platforms::PlatformFactory::InterruptionEvent event) = 0;
				static zeus::platforms::PlatformFactory& getInstance();
		};
	}
}

#include <functional>
#include <type_traits>

#define HASH_ZEUS_ENUM_OVERLOAD (ZEUS_ENUM) 												\
namespace std {																\
	template<>															\
		struct hash<ZEUS_ENUM> {												\
			size_t operator()(const ZEUS_ENUM& e) const { 									\
				return hash< underlying_type<ZEUS_ENUM>::type >()(static_cast< underlying_type<ZEUS_ENUM>::type >(e)); 	\
			}														\
		};															\
}

HASH_ZEUS_ENUM_OVERLOAD(zeus::platforms::CommunicationChannel)
HASH_ZEUS_ENUM_OVERLOAD(zeus::platforms::AnalogResolution)
HASH_ZEUS_ENUM_OVERLOAD(zeus::platforms::InterruptionEvent)
HASH_ZEUS_ENUM_OVERLOAD(zeus::platforms::Timers)
HASH_ZEUS_ENUM_OVERLOAD(zeus::platforms::TimersMode)
