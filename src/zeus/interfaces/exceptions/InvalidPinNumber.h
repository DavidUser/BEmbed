#pragma once

#include <stdexcept>

namespace zeus {
	namespace interfaces {
		namespace exceptions {
			class InvalidPinNumber : public std::out_of_range {

			private:
				unsigned number;

			public:
				InvalidPinNumber(unsigned number);

				const unsigned& getNumber() const;
			};
		}
	}
}
