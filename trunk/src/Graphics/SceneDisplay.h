#ifndef scenedisplay_h
#define scenedisplay_h

#include "Drawable.h"
#include "MeshRenderer.h"

#include "../SceneObjects/Primitives/Cube.h"
#include "../SceneObjects/Primitives/Box.h"
#include "../SceneObjects/Maps/Map.h"

class SceneDisplay : public Drawable, public MeshRenderer
{
private:
	Mesh** meshes;

public:
	SceneDisplay() : Drawable(0)
	{
		meshes = new Mesh*[5];

		meshes[0] = new Cube(0.25f, Position3(0, 0, 0));
		meshes[1] = new Box(Dimension3(0.2f, 1.5f, 2.f), Position3(-1.5, 0.25, 0));
		meshes[2] = new Box(Dimension3(2.f, 1.5f, 0.2f), Position3(0, 0.25, -2));
		meshes[3] = new Box(Dimension3(0.05f, 4.f, 0.05f), Position3(1.5, 1.5, -2));
		meshes[4] = new Box(Dimension3(5.f, 0.05f, 5.f), Position3(0, -0.5, 0));


	}

	virtual ~SceneDisplay()
	{
		for(int i = 0; i < 5; i++)
			delete meshes[i];
		delete [] meshes;
	}

	void draw()
	{
		for(int i = 0; i < 5; i++)
			drawMesh(meshes[i]);
	}
};

#endif
