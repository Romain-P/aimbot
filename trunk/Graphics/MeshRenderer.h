#ifndef meshrenderer_h
#define meshrenderer_h

#include "../SceneObjects/Primitives/PrimitiveMesh.h"
#include "../SceneObjects/Mesh.h"

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
		for (unsigned int face = 0; face < mesh->faces.size(); face++)
		{
			int isize = mesh->faces.at(face).indices.size();

			glBegin(GL_POLYGON);
			for (unsigned int i = 0; i < isize; i++)
			{
				int index = mesh->faces.at(face).indices.at(i);
				glVertex3f(mesh->vertices.at(index).x,
						mesh->vertices.at(index).y,
						mesh->vertices.at(index).z);
			}
			glEnd();
		}
	}
};

#endif
