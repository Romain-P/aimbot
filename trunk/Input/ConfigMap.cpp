#include "ConfigMap.h"

ConfigMap::ConfigMap()
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
		key = line.substr(0, eqIndex);
		value = line.substr(eqIndex, line.length());

		config[key] = value;
	}
}

string ConfigMap::getConfigValue(string key)
{
	return config[key];
}
