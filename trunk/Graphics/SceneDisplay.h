#ifndef scenedisplay_h
#define scenedisplay_h

#include "Drawable.h"
#include "MeshRenderer.h"

#include "../SceneObjects/Primitives/Cube.h"
#include "../SceneObjects/Primitives/Box.h"
#include "../SceneObjects/Maps/Map.h"

class SceneDisplay : public Drawable
{
private:
	Map* map;
	Box* box;
	Cube* cube;

public:
	SceneDisplay() : Drawable(0)
	{
		cube = new Cube(2.0f);
		box = new Box(1.5f, 2.f, 3.f);
	}

	void draw()
	{
		glColor3f(0, 1, 0);
		glPushMatrix();
			MeshRenderer::draw(cube);
			glTranslatef(-5, 0, 0);
			MeshRenderer::draw(box);
		glPopMatrix();
	}
};

#endif
