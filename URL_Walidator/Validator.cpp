#pragma once
#include "Validator.hpp"

void Validator::validateObtainedData(vector<string>& addresses) {
	auto it = addresses.begin();

	while (it != addresses.end()) {
		//methods here
	}
}

void Validator::validateURLProtocol(string URL) {
	size_t found=URL.find("://");
	if (found != string::npos) {
		string protocol = URL.substr(0, found);
		if (protocol == "ftp" || protocol == "http" || protocol == "https") {

		}
		else {
			//Output Handler WRONG PROTOCOL
		}
	}
	else {
		//Output Handler " :// " NOT FOUND 
	}
}