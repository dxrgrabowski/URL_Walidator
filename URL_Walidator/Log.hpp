#pragma once
#include <string>
#include <vector>
#include "List.hpp"

class Log {
private:
	DoublyLinkedList<std::vector<std::string>> logs;
	std::vector<std::string> messages;
public:
	Log() {

	}
	void pushLog(std::vector<std::string> messages) {
		logs.add(messages);
	}
	void addNewMessage(std::string message) {
		messages.push_back(message);
	}
}