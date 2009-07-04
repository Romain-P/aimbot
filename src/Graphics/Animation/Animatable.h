#ifndef animatable_h
#define animatable_h

#include <vector>
#include <iostream>
#include "../Drawable.h"

using std::vector;

class AnimationStage;

class Animatable : public Drawable
{
private:
	int stage;
	void stopAnimation();

protected:
	bool animating;

	vector<AnimationStage*> stages;

public:
	Animatable();
	virtual ~Animatable();
	void startAnimation();
	void update(float timestep);
	void expireStage();
	void draw();
	void animate();
	void setStage(int stage);
};

#endif
