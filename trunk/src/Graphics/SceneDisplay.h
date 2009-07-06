#ifndef scenedisplay_h
#define scenedisplay_h

#include "Drawable.h"
#include "MeshRenderer.h"

#include "../Graphics/Animation/Animator.h"
#include "../Graphics/Animation/Animatable.h"
#include "../Graphics/Materials.h"
#include "../Graphics/Animation/RotatingBlock.h"
#include "../SceneObjects/Maps/Map.h"

class SceneDisplay : public Drawable, public MeshRenderer
{
private:
	Animator* animator;
	Animatable** blocks;
	MeshOFF* mesh;

	void initSceneObjects()
	{
		mesh = new MeshOFF("D:/CS/Workspace/AIm/data/meshes/test.off");
		mesh ->setCentre(Position3(0, -0.5f, 0));

		blocks = new Animatable*[3];
		blocks[0] = new RotatingBlock(50, 0.3f, Position3(0, 0.25f, 0));
		blocks[1] = new RotatingBlock(100, 0.1f, Position3(-0.1f, 0.6f, 0));
		blocks[2] = new RotatingBlock(300, 0.03f, Position3(-0.2f, 0.75f, 0));

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
		delete mesh;

		for(int i = 0; i < 3; i++)
			delete blocks[i];
		delete [] blocks;
	}

	void draw()
	{
		for(int i = 0; i < 1; i++)
		{
			Position3 c = mesh->getCentre();
			glPushMatrix();
				Materials::none();
				glTranslatef(c.x, c.y, c.z);
				drawMesh(mesh);
			glPopMatrix();
		}

		for(int i = 0; i < 3; i++)
			blocks[i]->draw();
	}
};

#endif
