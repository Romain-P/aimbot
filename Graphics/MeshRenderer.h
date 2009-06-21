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
		for (int face = 0; face < mesh->numFaces; face++)
		{
			glBegin(GL_POLYGON);
			for (int vert = 0; vert < mesh->faces[face].nVerts; vert++)
			{
				int nIndex = mesh->faces[face].verts[vert].normIndex;
				int vIndex = mesh->faces[face].verts[vert].vertIndex;
				glNormal3f(mesh->flatNorms[nIndex].x,
						mesh->flatNorms[nIndex].y,
						mesh->flatNorms[nIndex].z);
				glVertex3f(mesh->points[vIndex].x,
						mesh->points[vIndex].y,
						mesh->points[vIndex].z);
			}
			glEnd();
		}
	}

	static void draw(PrimitiveMesh* mesh)
	{
		vector<PrimitiveFace> faces = mesh->getFaces();
		vector<Vector3> vertices = mesh->getVertices();
		vector<PrimitiveFace>::const_iterator it;

		glBegin(GL_QUADS);
		for (it = faces.begin(); it != faces.end(); ++it)
		{
			unsigned int isize = it->indices.size();
			for(unsigned int i = 0; i < isize; i++)
			{
				Vector3& v = vertices.at(it->indices.at(i));
				glVertex3f(v.x, v.y, v.z);
			}
		}
		glEnd();
	}
};

#endif
