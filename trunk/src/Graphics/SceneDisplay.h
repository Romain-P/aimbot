#ifndef scenedisplay_h
#define scenedisplay_h

#include "Drawable.h"
#include "MeshRenderer.h"

#include "../Graphics/Animation/Animator.h"
#include "../Graphics/Animation/Animatable.h"
#include "../Graphics/Materials.h"
#include "../Graphics/Animation/RotatingBlock.h"
#include "../SceneObjects/Maps/Map.h"

using std::cout;
using std::endl;

class SceneDisplay : public Drawable, public MeshRenderer
{
private:
	Animator* animator;
	Animatable** blocks;

	MeshOBJ* textured;
	MeshOBJ* signature;

	void initSceneObjects()
	{
		textured = new MeshOBJ();
		textured->setCentre(Position3(0, -0.5f, 0));
		textured->read("testmap.obj");
		textured->loadTexture("testmap.png");

		blocks = new Animatable*[3];
		blocks[0] = new RotatingBlock(50, 0.15f, Position3(0, 0.25f, 0));
		blocks[1] = new RotatingBlock(100, 0.05f, Position3(-0.1f, 0.6f, 0));
		blocks[2] = new RotatingBlock(300, 0.015f, Position3(-0.2f, 0.75f, 0));

		for(int i = 0; i < 3; i++)
			animator->addAnimatable(blocks[i]);
	}


public:
	SceneDisplay(Animator* animator) : Drawable(0)
	{
		this->animator = animator;
		initSceneObjects();
	}

	virtual ~SceneDisplay()
	{
		//delete mesh;

		for(int i = 0; i < 3; i++)
			delete blocks[i];
		delete [] blocks;

		delete textured;
		//delete signature;
	}

	void draw()
	{
		Position3 c = textured->getCentre();
		glPushMatrix();
			//Materials::none();
			glTranslatef(c.x, c.y, c.z);
			drawTexturedMesh(textured);
		glPopMatrix();

		for(int i = 0; i < 3; i++)
			blocks[i]->draw();
	}
};

#endif
