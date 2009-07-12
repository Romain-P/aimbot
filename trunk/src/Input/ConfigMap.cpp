#include "ConfigMap.h"

ConfigMap::ConfigMap()
{
	file.open(Filenames::config.c_str(), std::ios::in);
	if(!file)
		cout << "Opening " << Filenames::config << " failed." << endl;

	int eqIndex;
	string line;
	string key;
	string value;

	while(file >> line)
	{
		eqIndex = line.find_first_of("=", 0);
		key = line.substr(0, eqIndex);
		value = line.substr(eqIndex + 1);

		config[key] = value;
	}
}

const string& ConfigMap::get(const string& key)
{
	return config[key];
}
