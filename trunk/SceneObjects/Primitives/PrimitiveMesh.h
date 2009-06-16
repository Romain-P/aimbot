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

class PrimitiveMesh : public Drawable
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


	/*
	 * Somewhat slow due to generality, may specialize to
	 * GL_QUADS, or GL_TRIANGLES if needed
	 */
	void draw()
	{
		for(unsigned int face = 0; face < faces.size(); face++)
		{
			glBegin(GL_POLYGON);
			for(unsigned int i = 0; i < faces.at(face).indices.size(); i++)
			{
				int index = faces.at(face).indices.at(i);
				glVertex3f(vertices.at(index).x, vertices.at(index).y, vertices.at(index).z);
			}
			glEnd();
		}
	}
};

#endif
