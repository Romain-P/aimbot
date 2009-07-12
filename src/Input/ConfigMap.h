#ifndef configmap_h
#define configmap_h

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Filenames.h"
#include "../Utils/Structures/Singleton.h"

using std::cout;
using std::endl;
using std::map;
using std::fstream;
using std::stringstream;
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
	const string& get(const string& key);
};

#endif
