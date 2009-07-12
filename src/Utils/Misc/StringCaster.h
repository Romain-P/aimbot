#ifndef stringcaster_h
#define stringcaster_h

#include <string>
#include <sstream>
#include <cstdlib>
#include <typeinfo>
#include <iostream>

using std::string;
using std::stringstream;

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
		/*
		T temp;
		stringstream ss;
		ss << str;
		ss >> temp;
		std::cout << temp << std::endl;
		return temp;
		*/


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
