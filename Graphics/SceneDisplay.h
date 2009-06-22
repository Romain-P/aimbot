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
	Box* box1;
	Box* box2;
	Cube* cube;

public:
	SceneDisplay() : Drawable(0)
	{
		cube = new Cube(1.0f);
		box1 = new Box(0.2f, 1.5f, 2.f);
		box2 = new Box(2.f, 0.5f, 0.2f);
	}

	void draw()
	{
		glPushMatrix();

			MeshRenderer::draw(cube);

			glTranslatef(-1.5, 0.25, 0);
			MeshRenderer::draw(box1);

			glTranslatef(0, 0, -3);
			MeshRenderer::draw(box2);

		glPopMatrix();
	}
};

#endif
