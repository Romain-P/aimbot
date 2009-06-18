#ifndef configmap_h
#define configmap_h

#include <map>
#include <fstream>
#include <string>
#include "FileNameStore.h"

using std::fstream;
using std::string;

class ConfigMap
{
private:
	Map<string, string> map;
	fstream file;

public:
	ConfigMap()
	{
		file.open(FileNameStore::config, std::ios::in);
		int eqIndex;
		string line;
		string key;
		string value;

		// TODO: probably an off-by-one here for the index
		while(file >> line)
		{
			eqIndex = line.find_first_of("=", 0);
			key = line.substring(0, eqIndex);
			value = line.substring(eqIndex, line.length());

			map[key] = value;
		}
	}

	string getConfigValue(string key)
	{
		return map[key];
	}
};

#endif
