#ifndef primitivemesh_h
#define primitivemesh_h

#include <vector>
#include "PrimitiveFace.h"
#include "../../Graphics/Drawable.h"
#include "../../Utils/Structures/Vector3.h"

using std::vector;

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
