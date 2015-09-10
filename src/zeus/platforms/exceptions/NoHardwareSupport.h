#pragma once

#include <string>

namespace zeus {
	namespace platforms {
		namespace exceptions {
			class NoHardwareSupport {
			private:
				std::string similarResources;

			public:
				void NoHardwareSupport(std::string similarResources = "");
				std::string getSimilarResources();
				void setSimilarResources(std::string similarResources);
			};
		}
	}
}
