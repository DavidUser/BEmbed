namespace zeus {
	namespace platforms {
		namespace exceptions {
			class NoHardwareSuport {
			private:
				std::string similarResources;

			public:
				void NoHardwareSupport(std::string similarResources = "");
				std::string getSimilarResources();
				void setSimilarResources(std::string similarResources);
				void NoHardwareSupport(std::string similarResources = "");
				void setSimilarResources(std::string similarResources);
			};
		}
	}
}
