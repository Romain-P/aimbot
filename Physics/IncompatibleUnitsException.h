#ifndef incompatibleunitsexception_h
#define incompatibleunitsexception_h

#include <exception>

class IncompatibleUnitsException : public Exception
{
	virtual const char* what() const throw()
	{
		return "Error: attempted to perform operation on physical values with differing units";
	}
};

#endif
