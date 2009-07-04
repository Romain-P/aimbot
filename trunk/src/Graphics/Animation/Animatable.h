#ifndef animatable_h
#define animatable_h

#include <vector>
#include "../Drawable.h"

using std::vector;

class AnimationStage;

class Animatable : public Drawable
{
private:
	vector<AnimationStage*>::const_iterator stageIter;

	void stopAnimation();

protected:
	bool animating;

	vector<AnimationStage*> stages;

public:
	Animatable();
	void startAnimation();
	void update(float timestep);
	void expireStage();
	void draw();
	void animate();
};

#endif
