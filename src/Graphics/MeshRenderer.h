#ifndef meshrenderer_h
#define meshrenderer_h

#include <vector>

#include "../SceneObjects/Meshes/Mesh.h"
#include "../SceneObjects/Meshes/MeshOFF.h"
#include "../SceneObjects/Meshes/MeshOBJ.h"

using std::vector;

class MeshRenderer
{
private:
protected:
	void drawMesh(Mesh* mesh)
	{
		const vector<Face>& faces = mesh->getFaces();
		const vector<Position3>& vertices = mesh->getVertices();
		vector<Face>::const_iterator it;

		glBegin(GL_QUADS);
		for (it = faces.begin(); it != faces.end(); ++it)
		{
			for(int i = 0; i < it->order; i++)
			{
				const Position3& p = vertices.at(it->indices[i]);
				glVertex3f(p.x, p.y, p.z);
			}
		}
		glEnd();
	}

	void drawTexturedMesh(MeshOBJ* mesh)
	{
		const vector<TexFace>& texFaces = mesh->getTexFaces();
		const vector<Position2>& texCoords = mesh->getTexCoords();
		const vector<Position3>& vertices = mesh->getVertices();
		vector<TexFace>::const_iterator it;

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glBegin(GL_QUADS);

		for (it = texFaces.begin(); it != texFaces.end(); ++it)
		{
			for(int i = 0; i < it->order; i++)
			{
				const Position3& p = vertices[it->indices[i]];
				const Position2& t = texCoords[it->texIndices[i]];
				glTexCoord2f(t.x, t.y);
				glVertex3f(p.x, p.y, p.z);
			}
		}

		glEnd();
	}


	/*
			if(it->order == 4)
			{
				for(int i = 0; i < it->order; i++)
				{
					const Position3& p = vertices.at(it->indices[i]);
					const Position2& t = texCoords.at(it->texIndices[i]);
					glTexCoord2f(t.x, t.y);
					glVertex3f(p.x, p.y, p.z);
				}
			}
			else if(it->order == 3)
			{
				glEnd();
				glBegin(GL_TRIANGLES);
				for(int i = 0; i < it->order; i++)
				{
					const Position3& p = vertices.at(it->indices[i]);
					const Position2& t = texCoords.at(it->texIndices[i]);
					glTexCoord2f(t.x, t.y);
					glVertex3f(p.x, p.y, p.z);
				}
				glEnd();
				glBegin(GL_QUADS);
			}

	 */
};

#endif
