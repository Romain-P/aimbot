#ifndef rotatingblock_h
#define rotatingblock_h

#include "Animatable.h"
#include "AnimationStage.h"
#include "../Materials.h"
#include "../MeshRenderer.h"
#include "../../SceneObjects/Primitives/Cube.h"

class RotationStage : public AnimationStage, public MeshRenderer
{
private:
	Position3 centre;
	MeshOBJ* mesh;
	float rotation;
	float speed;
	float size;
public:
	RotationStage(float speed, float size, MeshOBJ* mesh) :
		AnimationStage(AnimationStage::INFINITE_TIME)
	{
		this->speed = speed;
		this->mesh = mesh;
		this->size = size;
		centre = mesh->getCentre();
	}

	void draw()
	{
		//Materials::glowing(1.f, 0.6f, 0.2f);
		glColor3f(0.3f, 0.6f, 0.2f);
		glPushMatrix();
			glTranslatef(centre.x, centre.y, centre.z);
			glScalef(size, size, size);
			glRotatef(rotation, 0.f, 0.f, 1.f);
			glRotatef(rotation * 0.3f, 0.f, 1.f, 0.f);
			//drawTexturedMesh(mesh);
		glPopMatrix();

	}

	void animate()
	{
		rotation = speed * timeElapsed;
	}
};

class RotatingBlock : public Animatable
{
private:

	MeshOBJ* cube;
public:
	RotatingBlock(float speed, float size, Position3 position) : Animatable()
	{
		cube = new MeshOBJ();
		cube->read("D:/CS/Workspace/AIm/data/meshes/gold.obj");
		cube->loadTexture("D:/CS/Workspace/AIm/data/textures/gold.png");
		cube->setCentre(position);

		stages.push_back(new RotationStage(speed, size, cube));
		startAnimation();
	}
	~RotatingBlock()
	{
		delete cube;
	}
};

#endif
