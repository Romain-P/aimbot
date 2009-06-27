#ifndef primitiveface_h
#define primitiveface_h

#include <vector>

using std::vector;

/*
 * Holds the index of each defining vertex of the face
 */
class PrimitiveFace
{
public:
	vector<int> indices;

	PrimitiveFace(int a, int b, int c, int d)
	{
		indices.push_back(a);
		indices.push_back(b);
		indices.push_back(c);
		indices.push_back(d);
	}

	/* having some nasty problems with this fucker
	PrimitiveFace(int a, ...)
	{
		va_list listArgs;
		va_start(listArgs, a);

		for(int currentArg = a; currentArg != -1; currentArg = va_arg(listArgs, int))
		{
			indices.push_back(currentArg);
		}

		va_end(listArgs);
	}
	*/
};

#endif
