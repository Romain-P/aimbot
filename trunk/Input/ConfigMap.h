#ifndef configmap_h
#define configmap_h

#include <map>
#include <fstream>
#include <string>
#include "FileNameStore.h"
#include "../Utils/Structures/Singleton.h"

using std::fstream;
using std::string;
using std::map;

class ConfigMap : public Singleton<ConfigMap>
{
private:
	map<string, string> config;
	fstream file;

	//private constructor forces use of ConfigMap::instance()
	ConfigMap();

public:
	string getConfigValue(string key);
};

#endif
