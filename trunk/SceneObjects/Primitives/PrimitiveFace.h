#ifndef primitiveface_h
#define primitiveface_h

#include <vector>
#include <stdio.h>
#include <stdarg.h>

using std::vector;

/*
 * Holds the index of each defining vertex of the face
 */
class PrimitiveFace
{
public:
	vector<int> indices;

	PrimitiveFace(int a, ...)
	{
		va_list listArgs;
		va_start(listArgs, a);

		int currentArg = a;
		while(currentArg != -1)
		{
			indices.push_back(a);
			currentArg = va_arg(listArgs, int);
		}

		va_end(listArgs);
	}
};

#endif
