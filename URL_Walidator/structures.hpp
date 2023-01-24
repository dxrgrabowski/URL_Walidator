#pragma once
#include <string>

using namespace std;

struct Url {
	bool hasColonSlashSlash = 0;
	string protocol;
	string subdomain;
	string secondLevelDomain;
	string topLevelDomain;
	string path;
	string params;
	string anchor;
};