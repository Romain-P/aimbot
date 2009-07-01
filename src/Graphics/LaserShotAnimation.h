#ifndef lasershotanimation_h
#define lasershotanimation_h

#include "Animatable.h"
#include "../Utils/Math/Random.h"

class LaserShotAnimation : public Animatable
{
private:
	float baseWidth;
	float currWidth;
	float p;

	void calcWidth()
	{
		currWidth = baseWidth * p * p + 1;
	}
public:
	LaserShotAnimation() : Animatable(0.2f)
	{
		baseWidth = 20.f;
		currWidth = 1.f;
	}

	void animate()
	{
		p = progress();
		calcWidth();
	}

	void draw()
	{
		if(!animating)
			return;

		glBegin(GL_QUADS);
			glColor4f(1, 1, 1, 0);
			glVertex2f(width * 0.75f + currWidth, height);
			glVertex2f(halfWidth + 1.f, halfHeight);
			glColor4f(1, 1, 1, 1);
			glVertex2f(halfWidth, halfHeight);
			glVertex2f(width * 0.75f, height);

			glColor4f(1, 1, 1, 0);
			glVertex2f(width * 0.75f - currWidth, height);
			glVertex2f(halfWidth - 1.f, halfHeight);
			glColor4f(1, 1, 1, 1);
			glVertex2f(halfWidth, halfHeight);
			glVertex2f(width * 0.75f, height);
		glEnd();
	}
};

#endif
