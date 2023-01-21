#pragma once
#include <string>
#include <vector>

using namespace std;

class Validator {
	
	vector<string> workAddresses;

public:
	Validator(vector<string> addresses) {
		validateObtainedData(addresses);
	}
	~Validator()=default;

	//Summarizing method
	void isValidURL(vector<string>& addresses);
	
	//Checks if protocol and "://" is present and valid in URL adress http/https/ftp
	void validateURLProtocol(string URL);
	//Checks if domain is present and valid in URL adress 
	void validateURLDomain();


}