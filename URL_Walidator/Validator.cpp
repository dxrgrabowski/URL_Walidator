#pragma once
#include "Validator.hpp"


void Validator::isValidURL(vector<string>& addresses) {

	for (string address : addresses) {
		Validator::validateURLProtocol(address);
		Validator::validateSubdomain(address);
		Validator::validateTLD(address);
		Validator::validatePath(address);
		Validator::validateAnchor(address);
		Validator::validateParam(address);
	}
}

void Validator::validateURLProtocol(string URL) {
	size_t found=URL.find("://");
	if (found != string::npos) {
		string protocol = URL.substr(0, found);
		if (protocol == "ftp" || protocol == "http" || protocol == "https") {
			this->logs.addNewMessage("Protocol valid : " + protocol);
		}
		else {
			this->logs.addNewMessage("Unknnown protocol : " + protocol);
		}
	}
	else {
		this->logs.addNewMessage(":// element is missing in URL adress");
	}
}

void Validator::validateSubdomain(string URL) {
	size_t pos = URL.find("://");

	size_t posLast = URL.find_last_of('.');
	if (pos == string::npos) {
		this->logs.addNewMessage("domain is not valid, there are no obligatory TLD (top-level domain)");
	}

	size_t posFirst = URL.find('.');
	if (posFirst == string::npos) {
		this->logs.addNewMessage("domain is not valid, there are no obligatory TLD (top-level domain)");
	}


	if (posFirst == pos) {
		urlParts.secondLevelDomain = URL.substr(pos + 3, posLast - pos - 3);
	}
	else {
		urlParts.subdomain = URL.substr(pos + 3, posFirst);
	}

}

void Validator::validatePath(string URL) {
	
	string path = "";

	size_t protocol_end = URL.find("://");
	if (protocol_end != std::string::npos) {
		size_t pathStart = URL.find("/", protocol_end + 3);
		if (pathStart != std::string::npos) {
			path = URL.substr(pathStart);
		}
	}
	
	urlParts.path = path;
}

void Validator::validateTLD(string URL) {
	size_t pos = URL.find("://");

	size_t posLast = URL.find_last_of('.');

	size_t pathStart = URL.find("/", pos + 3);

	urlParts.topLevelDomain = URL.substr(posLast, pathStart);

}

void Validator::validateAnchor(string URL) {
	
	string anchor;
	size_t anchorPos = URL.find("#");
	if (anchorPos != std::string::npos) {
		anchor = URL.substr(anchorPos + 1);
	}
	
	urlParts.anchor = anchor;
}

void Validator::validateParam(string URL) {
	string params;
	size_t paramsPos = URL.find("?");
	if (paramsPos != std::string::npos) {
		params = URL.substr(paramsPos + 1);
	}
	urlParts.params = params;
}