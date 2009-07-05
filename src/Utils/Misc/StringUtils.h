#ifndef stringutils_h
#define stringutils_h

#include <string>

using std::string;

namespace StringUtils
{
	static void toLower(string& str)
	{
		for(unsigned int i = 0; i < str.length(); i++)
			str[i] = tolower(str[i]);
	}
};

#endif
