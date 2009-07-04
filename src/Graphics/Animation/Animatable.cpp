#include "Animatable.h"
#include "AnimationStage.h"

//prevent null pointers by initializing vector with this dummy stage
class NullStage : public AnimationStage
{
public:
	NullStage() : AnimationStage(0) {}
	void draw() {}
	void animate() {}
};


Animatable::Animatable() :
		animating(false)
{
	stages.push_back(new NullStage());
	stageIter = stages.begin();
}

void Animatable::stopAnimation()
{
	animating = false;
}

void Animatable::startAnimation()
{
	stageIter = stages.begin();
	animating = true;
}

void Animatable::update(float timestep)
{
	if (!animating)
		return;

	if ((*stageIter)->hasExpired()) {
		if (stageIter == stages.end()) {
			stopAnimation();
			return;
		}
		++stageIter;
	}
	else {
		(*stageIter)->timeElapsed += timestep;
	}

	animate();
}

void Animatable::expireStage()
{
	(*stageIter)->setExpired();
}

void Animatable::draw()
{
	if(animating)
		(*stageIter)->draw();
}

void Animatable::animate()
{
	(*stageIter)->animate();
}
