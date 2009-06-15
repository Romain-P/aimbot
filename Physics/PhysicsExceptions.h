#ifndef physicsexceptions_h
#define physicsexceptions_h

#include <exception>

using namespace std;

class IncompatibleUnitsException : public exception
{
	virtual const char* what() const throw()
	{
		return "Error: attempted to perform operation on physical values with differing units";
	}
};

class DivisionByZeroException : public exception
{
	virtual const char* what() const throw()
	{
		return "Error: division by zero";
	}
};


#endif
