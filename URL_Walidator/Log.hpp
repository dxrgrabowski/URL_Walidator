#pragma once
#include <string>
#include <vector>
#include "List.hpp"
#include "structures.hpp"

class Log {
private:
public:
	std::vector<struct Url> multipleUrlInfo;

	void pushLog(struct Url data) {
		multipleUrlInfo.push_back(data);
	}
};