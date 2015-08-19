#pragma once

#include "../platforms/PlatformFactory.h"
#include <map>
#include <unordered_set>
#include <unordered_map>
#include "exception/InvalidInterruptEvent.h"

namespace zeus {
	namespace interfaces {
		class Interruption {
		public:
			using FunctionType = void(*)();
		private:
			//TODO can be useful define priority of execution an use ordered (commum) set and map
			std::unordered_set<FunctionType> functionsToEveryEvent;
			std::unordered_map<platforms::PlatformFactory::InterruptionEvent, FunctionType> functionsWithSpecificEvent;

		private:
			virtual platforms::PlatformFactory::InterruptionEvent getCurrentEvent() const noexcept = 0;
		public:

			/* return the Interrupt Events associated with this Interrupt */
			virtual const std::unordered_set<platforms::PlatformFactory::InterruptionEvent> &getActivations() const noexcept = 0;
			/* Add a function to execute when any Interrupt Event of this interruption occur */
			void addUserFunction(const FunctionType function);
			/* Add a function to execute when an specific Interrupt Event occur */
			void addUserFunction(const FunctionType function, const zeus::platforms::PlatformFactory::InterruptionEvent event);
			/* Executes all functions added,
			   no exception can be throwed in this section of code because it's a critical region */
			virtual void execute() const noexcept;
		};
	}
}
