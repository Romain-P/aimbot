#ifndef configmap_h
#define configmap_h

#include <map>
#include <iostream>
#include <fstream>
#include <string>

#include "Filenames.h"
#include "../Utils/Structures/Singleton.h"

using std::cout;
using std::endl;
using std::map;
using std::fstream;
using std::string;

class ConfigMap : public Singleton<ConfigMap>
{
private:
	map<string, string> config;
	fstream file;

protected:
	friend class Singleton<ConfigMap>;
	ConfigMap();

public:
	const string& getConfigValue(const string& key);
};

#endif
