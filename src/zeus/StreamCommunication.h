namespace zeus {
	class StreamCommunication {
	private:
		char stringTokenDelimiter;
		std::unique_ptr<zeus::interfaces::Communication> communication;

	public:
		StreamCommunication(std::unique_ptr<zeus::interfaces::Communication> communication);
		zeus::StreamCommunication& operator<<(std::string value);
		zeus::StreamCommunication& operator<<(unsigned long long value);
		zeus::StreamCommunication& operator<<(Byte value);
		zeus::StreamCommunication& operator<<(bool value);
		void operator<<(SerialControl control);
		char get();
		std::string getline(char delimiter = '\n');
		zeus::StreamCommunication& operator>>(char delimiter);
		zeus::StreamCommunication& operator>>(std::string& value);
		zeus::StreamCommunication& operator>>(unsigned long long& value);
		zeus::StreamCommunication& operator>>(Byte& value);
		zeus::StreamCommunication& operator>>(bool& value);
		void operator>>(zeus::StreamCommunication::SerialControl value);
		StreamCommunication(std::unique_ptr<zeus::interfaces::Communication> communication);
		zeus::StreamCommunication& operator<<(std::string value);
		zeus::StreamCommunication& operator<<(unsigned long long value);
		zeus::StreamCommunication& operator<<(Byte value);
		zeus::StreamCommunication& operator<<(bool value);
		void operator<<(SerialControl control);
		zeus::StreamCommunication& operator>>(char delimiter);
		zeus::StreamCommunication& operator>>(std::string& value);
		zeus::StreamCommunication& operator>>(unsigned long long& value);
		zeus::StreamCommunication& operator>>(Byte& value);
		zeus::StreamCommunication& operator>>(bool& value);
		void operator>>(zeus::StreamCommunication::SerialControl value);

		enum SerialControl {
			endl, binary, decimal, hexadecimal, octal
		};
	};
}
