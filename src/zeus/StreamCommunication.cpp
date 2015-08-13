#include "StreamCommunication.h"

zeus::StreamCommunication::StreamCommunication(std::unique_ptr<zeus::interfaces::Communication> communication) {
	// TODO - implement StreamCommunication::StreamCommunication
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator<<(std::string value) {
	// TODO - implement StreamCommunication::operator<<
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator<<(unsigned long long value) {
	// TODO - implement StreamCommunication::operator<<
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator<<(Byte value) {
	// TODO - implement StreamCommunication::operator<<
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator<<(bool value) {
	// TODO - implement StreamCommunication::operator<<
	throw "Not yet implemented";
}

void zeus::StreamCommunication::operator<<(SerialControl control) {
	// TODO - implement StreamCommunication::operator<<
	throw "Not yet implemented";
}

char zeus::StreamCommunication::get() {
	// TODO - implement StreamCommunication::get
	throw "Not yet implemented";
}

std::string zeus::StreamCommunication::getline(char delimiter) {
	// TODO - implement StreamCommunication::getline
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator>>(char delimiter) {
	// TODO - implement StreamCommunication::operator>>
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator>>(std::string& value) {
	// TODO - implement StreamCommunication::operator>>
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator>>(unsigned long long& value) {
	// TODO - implement StreamCommunication::operator>>
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator>>(Byte& value) {
	// TODO - implement StreamCommunication::operator>>
	throw "Not yet implemented";
}

zeus::StreamCommunication& zeus::StreamCommunication::operator>>(bool& value) {
	// TODO - implement StreamCommunication::operator>>
	throw "Not yet implemented";
}

void zeus::StreamCommunication::operator>>(zeus::StreamCommunication::SerialControl value) {
	// TODO - implement StreamCommunication::operator>>
	throw "Not yet implemented";
}
