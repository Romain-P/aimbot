#ifndef stringcaster_h
#define stringcaster_h

#include <string>
#include <cstdlib>
#include <typeinfo>

using std::string;

template <class T>
class StringCaster
{
private:
	static float floatType;
	static double doubleType;
	static int intType;
	static long longType;

public:
	static T cast(const string& str)
	{
		if(typeid(T) == typeid(floatType))
			return T(atof(str.c_str()));
		else if(typeid(T) == typeid(doubleType))
			return T(atof(str.c_str()));
		else if(typeid(T) == typeid(intType))
			return T(atoi(str.c_str()));
		else if(typeid(T) == typeid(longType))
			return T(atol(str.c_str()));
		else return T(0);
	}
};


#endif
