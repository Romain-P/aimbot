#ifndef rotatingblock_h
#define rotatingblock_h

#include "Animatable.h"
#include "AnimationStage.h"
#include "../MeshRenderer.h"
#include "../../SceneObjects/Primitives/Cube.h"

class RotationStage : public AnimationStage, public MeshRenderer
{
private:
	Mesh* cube;
	float rotation;
public:
	RotationStage() : AnimationStage(AnimationStage::INFINITE_TIME)
	{
		cube = new Cube(0.2f, Position3(0, 1, 0));
	}

	~RotationStage()
	{
		delete cube;
	}

	void draw()
	{
		static Position3 c = cube->getCentre();
		glPushMatrix();
			glTranslatef(c.x, c.y, c.z);
			glRotatef(rotation, 0.f, 0.f, 1.f);
			drawMesh(cube);
		glPopMatrix();
	}

	void animate()
	{
		rotation = 300.f * timeElapsed;
	}
};

class RotatingBlock : public Animatable
{
public:
	RotatingBlock() : Animatable()
	{
		stages.push_back(new RotationStage());
		startAnimation();
	}
};

#endif
