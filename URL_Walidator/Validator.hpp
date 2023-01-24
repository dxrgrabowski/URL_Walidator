#pragma once
#include "Log.hpp"
#include <string>
#include <vector>

using namespace std;

struct Url {
	string protocol;
	bool hasColonSlashSlash;
	string secondLevelDomain;
	string topLevelDomain;
	string subdomain;
	string path;
	string anchor;
	string params;
};

class Validator {
	vector<string> workAddresses;
	
	Url urlParts;
public:
	Log logs;

	Validator(vector<string> addresses) {
		validateObtainedData(addresses);
	}
	~Validator()=default;

	//Summarizing method
	void isValidURL(vector<string>& addresses);
	
	//Checks if protocol and "://" is present and valid in URL adress http/https/ftp
	void validateURLProtocol(string URL);
	//Check if subdomain exists
	void validateSubdomain(string URL);
	//Check if TLD exists
	void validateTLD(string URL);
	//Check if atribbutes exists
	void validatePath(string URL);
	//Check if anchor exists
	void validateAnchor(string URL);
	//Check if parameter exists
	void validateParam(string URL);


}