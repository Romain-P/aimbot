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
		animating(false),
		stage(0)
{
	stages.push_back(new NullStage());
}

Animatable::~Animatable()
{
	vector<AnimationStage*>::const_iterator it = stages.begin();
	while(it != stages.end())
	{
		delete *it;
		++it;
	}
}

void Animatable::stopAnimation()
{
	animating = false;
}

void Animatable::startAnimation()
{
	stage = 0;
	animating = true;
}

void Animatable::update(float timestep)
{
	if (!animating)
		return;

	if (stages.at(stage)->hasExpired())
	{
		if (stage == stages.size() - 1)
		{
			stopAnimation();
			return;
		}
		stages.at(stage)->timeElapsed = 0;
		++stage;
	}
	else
	{
		stages.at(stage)->timeElapsed += timestep;
	}

	animate();
}

void Animatable::expireStage()
{
	stages.at(stage)->setExpired();
}

void Animatable::draw()
{
	if(animating)
		stages.at(stage)->draw();
}

void Animatable::animate()
{
	stages.at(stage)->animate();
}

void Animatable::setStage(int stage)
{
	this->stage = stage;
}
