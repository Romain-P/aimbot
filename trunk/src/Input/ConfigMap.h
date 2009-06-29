#ifndef configmap_h
#define configmap_h

#include <map>
#include <fstream>
#include <string>

#include "Filenames.h"
#include "../Utils/Structures/Singleton.h"

using std::map;
using std::fstream;
using std::string;

class ConfigMap : public Singleton<ConfigMap>
{
private:
	map<string, string> config;
	fstream file;
	ConfigMap();

public:
	string getConfigValue(string key);
};

#endif
