#ifndef primitivemesh_h
#define primitivemesh_h

#include <vector>
#include <stdio.h>
#include <stdarg.h>
#include "../../Graphics/Drawable.h"
#include "../../Utils/Vector3.h"

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

class PrimitiveMesh
{
protected:
	vector<Vector3> vertices;
	vector<PrimitiveFace> faces;
public:
	vector<Vector3>& getVertices()
	{
		return vertices;
	}

	vector<PrimitiveFace>& getFaces()
	{
		return faces;
	}



};

#endif
