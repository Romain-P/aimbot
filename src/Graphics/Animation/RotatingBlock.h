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
	float currSize;
public:
	RotationStage(float speed, float size, MeshOBJ* mesh) :
		AnimationStage(AnimationStage::INFINITE_TIME)
	{
		this->speed = speed;
		this->mesh = mesh;
		this->size = size;
		currSize = size;
		centre = mesh->getCentre();
	}

	void draw()
	{
		//Materials::glowing(1.f, 0.6f, 0.2f);
		glColor4f(0.3f, 0.6f, 0.2f, 1.0f);
		glPushMatrix();
			glTranslatef(centre.x, centre.y, centre.z);
			glScalef(currSize, currSize, currSize);
			glRotatef(rotation, 0.f, 0.f, 1.f);
			glRotatef(rotation * 0.3f, 0.f, 1.f, 0.f);
			drawTexturedMesh(mesh);
		glPopMatrix();

	}

	void animate()
	{
		rotation = speed * timeElapsed;
		currSize = size * (0.75f + 0.25f * sinf(timeElapsed));
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
		cube->read("gold.obj");
		cube->loadTexture("gold.png");
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
