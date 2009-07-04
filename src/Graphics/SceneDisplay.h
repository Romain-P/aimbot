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
	Mesh** meshes;

	void initSceneObjects()
	{
		meshes = new Mesh*[1];
		meshes[0] = new Mesh("D:/CS/Workspace/AIm/data/meshes/test.off");
		meshes[0]->setCentre(Position3(0, -0.5f, 0));

		block = new RotatingBlock();
		animator->addAnimatable(block);
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
	}

	void draw()
	{
		static Position3 c = meshes[0]->getCentre();
		for(int i = 0; i < 1; i++)
		{
			glPushMatrix();
				glTranslatef(c.x, c.y, c.z);
				drawMesh(meshes[i]);
			glPopMatrix();
		}
		block->draw();
	}
};

#endif
