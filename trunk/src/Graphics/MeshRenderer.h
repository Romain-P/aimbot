#ifndef meshrenderer_h
#define meshrenderer_h

#include <vector>

#include "../SceneObjects/Primitives/PrimitiveMesh.h"
#include "../SceneObjects/Primitives/PrimitiveFace.h"
#include "../SceneObjects/Mesh.h"

using std::vector;

class MeshRenderer
{
public:
	static void draw(Mesh* mesh)
	{
		const vector<Face>& faces = mesh->getFaces();
		const vector<Position3>& vertices = mesh->getVertices();
		vector<Face>::const_iterator it;

		glBegin(GL_QUADS);
		for (it = faces.begin(); it != faces.end(); ++it)
		{
			for(int i = 0; i < 4; i++)
			{
				const Position3& p = vertices.at(it->indices[i]);
				glColor3f(p.x, p.y, p.z);
				glVertex3f(p.x, p.y, p.z);
			}
		}
		glEnd();
	}

	static void draw(PrimitiveMesh* mesh)
	{
		const vector<PrimitiveFace>& faces = mesh->getFaces();
		const vector<Vector3>& vertices = mesh->getVertices();
		vector<PrimitiveFace>::const_iterator it;

		glBegin(GL_QUADS);
		for (it = faces.begin(); it != faces.end(); ++it)
		{
			unsigned int isize = it->indices.size();
			for(unsigned int i = 0; i < isize; i++)
			{
				const Vector3& v = vertices.at(it->indices.at(i));
				glColor3f(v.x, v.y, v.z);
				glVertex3f(v.x, v.y, v.z);
			}
		}
		glEnd();
	}
};

#endif
