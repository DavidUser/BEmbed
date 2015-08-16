#pragma once

namespace zeus {
	namespace interfaces {
		namespace exceptions {
			class InvalidPinNumber {

			private:
				unsigned number;

			public:
				InvalidPinNumber(unsigned number);

				const unsigned& getNumber() const;
			};
		}
	}
}
