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
	Mesh* mesh;
	float rotation;
	float speed;
public:
	RotationStage(float speed, Mesh* mesh) :
		AnimationStage(AnimationStage::INFINITE_TIME)
	{
		this->speed = speed;
		this->mesh = mesh;
		centre = mesh->getCentre();
	}

	void draw()
	{
		//Materials::glowing(1.f, 0.6f, 0.2f);
		glColor3f(0.3f, 0.6f, 0.2f);
		glPushMatrix();
			glTranslatef(centre.x, centre.y, centre.z);
			glRotatef(rotation, 0.f, 0.f, 1.f);
			glRotatef(rotation * 0.3f, 0.f, 1.f, 0.f);
			drawMesh(mesh);
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

	Mesh* cube;
public:
	RotatingBlock(float speed, float size, Position3 position) : Animatable()
	{
		cube = new Cube(size, position);
		stages.push_back(new RotationStage(speed, cube));
		startAnimation();
	}
	~RotatingBlock()
	{
		delete cube;
	}
};

#endif
