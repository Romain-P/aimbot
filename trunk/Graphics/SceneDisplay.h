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
	Box* floor;
	Box* tall;
	Cube* cube;

public:
	SceneDisplay() : Drawable(0)
	{
		cube = new Cube(0.5f);
		box1 = new Box(0.2f, 1.5f, 2.f);
		box2 = new Box(2.f, 1.5f, 0.2f);
		tall = new Box(0.05f, 4.f, 0.05f);
		floor = new Box(5.f, 0.05f, 5.f);
	}

	virtual ~SceneDisplay()
	{
		delete cube;
		delete box1;
		delete box2;
		delete floor;
	}

	void draw()
	{
		MeshRenderer::draw(cube);

		glPushMatrix();
			glTranslatef(-1.5, 0.25, 0);
			MeshRenderer::draw(box1);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 0.25, -2);
			MeshRenderer::draw(box2);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.5, 1.5, -2);
			MeshRenderer::draw(tall);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, -0.5, 0);
			MeshRenderer::draw(floor);
		glPopMatrix();
	}
};

#endif
