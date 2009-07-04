#ifndef animator_h
#define animator_h

#include <vector>
#include "Animatable.h"

using std::vector;

class Animator
{
private:
	vector<Animatable*> animatables;

public:
	Animator()
	{
	}

	void addAnimatable(Animatable* animatable)
	{
		animatables.push_back(animatable);
	}

	void updateAnimations(float timestep)
	{
		static vector<Animatable*>::const_iterator it;

		for(it = animatables.begin(); it != animatables.end(); ++it)
			(*it)->update(timestep);
	}
};


#endif
