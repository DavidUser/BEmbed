namespace zeus {
	namespace platforms {
		namespace exceptions {
			template <typename Resource>
			class ResourceAlreadySupplied {
			private:
				std::string problemsOfConcurrentUse;

			public:
				ResourceAlreadySupplied(Resource resource);
				Resource getExistentResource();
				std::string getProblemsOfConcurrentUse();
				void setProblemsOfConcurrentUse(std::string problemsOfConcurrentUse);
				void setProblemsOfConcurrentUse(std::string problemsOfConcurrentUse);
			};
		}
	}
}
