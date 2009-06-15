#ifndef primitivemesh_h
#define primitivemesh_h

#include <vector>
#include <stdio.h>
#include "../../Utils/Vector3.h"

/*
 * Holds the index of each defining vertex of the face
 */
class PrimitiveFace
{
public:
	std::vector<int> indices;

	void setIndices(int a, ...)
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
	std::vector<Vector3*> vertices;
	std::vector<PrimitiveFace> faces;
public:
	std::vector<Vector3*>& getVertices()
	{
		return vertices;
	}

	std::vector<PrimitiveFace>& getFaces()
	{
		return faces;
	}
};

#endif
