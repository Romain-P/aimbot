#ifndef meshrenderer_h
#define meshrenderer_h

#include <vector>

#include "../SceneObjects/Mesh.h"

using std::vector;

class MeshRenderer
{
protected:
	void drawMesh(Mesh* mesh)
	{
		const Position3& c = mesh->getCentre();

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
				glVertex3f(p.x + c.x, p.y + c.y, p.z + c.z);
			}
		}
		glEnd();
	}
};

#endif
