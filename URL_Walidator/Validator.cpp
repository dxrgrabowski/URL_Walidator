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
		logs.pushLog(urlParts);
	}
}

void Validator::validateURLProtocol(string URL) {
	size_t found=URL.find("://");
	if (found != string::npos) {
		string protocol = URL.substr(0, found);
		urlParts.hasColonSlashSlash = 1;
		if (protocol == "ftp" || protocol == "http" || protocol == "https") {
			//this->logs.addNewMessage("Protocol valid : " + protocol);
			//cout << "Protocol valid : " + protocol;
			urlParts.protocol = protocol;
		}
		else {
			//this->logs.addNewMessage("Unknnown protocol : " + protocol);
		}
	}
	else {
		//this->logs.addNewMessage(":// element is missing in URL adress");
	}
}

void Validator::validateSubdomain(string URL) {
	
	size_t posSubStart = URL.find("://")+3;
	size_t pathStart = URL.find("/", posSubStart);
	string formPathtoSub = URL.substr(posSubStart, pathStart - posSubStart);

	size_t posLast = formPathtoSub.find_last_of('.');
	if (posSubStart == string::npos) {
		//this->logs.addNewMessage("domain is not valid, there are no obligatory TLD (top-level domain)");
	}
	size_t posFirst = formPathtoSub.find('.');
	if (posFirst == string::npos) {
		//this->logs.addNewMessage("domain is not valid, there are no obligatory TLD (top-level domain)");
	}
	cout << posFirst<<"|"<< posLast - posFirst << endl;

	if (posFirst == posLast) {
		urlParts.subdomain = "";
	}
	else {
		urlParts.subdomain = URL.substr(posSubStart, posFirst);
		urlParts.secondLevelDomain = URL.substr(posFirst, posLast - posFirst);
	}

}

void Validator::validatePath(string URL) {
	
	string path = "";
	size_t paramsPos = URL.find("?");
	size_t protocol_end = URL.find("://");
	if (protocol_end != std::string::npos) {
		size_t pathStart = URL.find("/", protocol_end + 3);
		if (pathStart != std::string::npos) {
			path = URL.substr(pathStart);
			if(paramsPos != std::string::npos)
				path = URL.substr(pathStart, paramsPos- pathStart);
		}
	}
	
	urlParts.path = path;
}

void Validator::validateTLD(string URL) {
	size_t posSubStart = URL.find("://");

	size_t posLast = URL.find_last_of('.');

	size_t pathStart = URL.find("/", posSubStart + 3);

	urlParts.topLevelDomain = URL.substr(posLast, pathStart-posLast);

}

void Validator::validateAnchor(string URL) {
	
	string anchor;
	size_t anchorPos = URL.find("#");
	if (anchorPos != std::string::npos) {
		anchor = URL.substr(anchorPos + 1);
	}
	else
		anchor = "";
	
	urlParts.anchor = anchor;
}

void Validator::validateParam(string URL) {
	string params;
	size_t paramsPos = URL.find("?");
	size_t anchorPos = URL.find("#");
	if (paramsPos != std::string::npos && anchorPos != std::string::npos) {
		if(anchorPos != std::string::npos)
			params = URL.substr(paramsPos + 1, anchorPos - 1 - paramsPos);
		else
			params = URL.substr(paramsPos + 1);
	}
	if (paramsPos == std::string::npos)
		params = "";

	urlParts.params = params;
}