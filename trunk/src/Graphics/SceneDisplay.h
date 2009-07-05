#ifndef scenedisplay_h
#define scenedisplay_h

#include "Drawable.h"
#include "MeshRenderer.h"

#include "../Graphics/Animation/Animator.h"
#include "../Graphics/Animation/Animatable.h"
#include "../Graphics/Animation/RotatingBlock.h"
#include "../SceneObjects/Maps/Map.h"

class SceneDisplay : public Drawable, public MeshRenderer
{
private:
	Animator* animator;
	Animatable* block;
	Animatable* block1;
	Animatable* block2;

	Mesh** meshes;

	void initSceneObjects()
	{
		meshes = new Mesh*[1];
		meshes[0] = new Mesh("D:/CS/Workspace/AIm/data/meshes/test.off");
		meshes[0]->setCentre(Position3(0, -0.5f, 0));

		block = new RotatingBlock(50, 0.3f, Position3(0, 0.25f, 0));
		block1 = new RotatingBlock(100, 0.1f, Position3(-0.1f, 0.6f, 0));
		block2 = new RotatingBlock(300, 0.03f, Position3(-0.2f, 0.75f, 0));

		animator->addAnimatable(block);
		animator->addAnimatable(block1);
		animator->addAnimatable(block2);
	}
public:
	SceneDisplay(Animator* animator) : Drawable(0)
	{
		this->animator = animator;
		initSceneObjects();
	}

	virtual ~SceneDisplay()
	{
		for(int i = 0; i < 1; i++)
			delete meshes[i];
		delete [] meshes;

		delete block;
		delete block1;
		delete block2;
	}

	void draw()
	{
		for(int i = 0; i < 1; i++)
		{
			Position3 c = meshes[i]->getCentre();
			glPushMatrix();
				glTranslatef(c.x, c.y, c.z);
				drawMesh(meshes[i]);
			glPopMatrix();
		}

		block->draw();
		block1->draw();
		block2->draw();
	}
};

#endif
