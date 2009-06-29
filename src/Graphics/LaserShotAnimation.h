#ifndef lasershotanimation_h
#define lasershotanimation_h

#include "Animatable.h"

class LaserShotAnimation : public Animatable
{
private:
	float baseWidth;
	float currWidth;
	float p;

	void calcWidth()
	{
		if(p < 0.5f)
			currWidth = 4 * baseWidth * p * p;
		else
			currWidth = 4 * baseWidth * (1 - p) * (1 - p);
	}
public:
	LaserShotAnimation() : Animatable(0.4f)
	{
		baseWidth = 10.f;
		currWidth = 0.f;
	}

	void animate()
	{
		p = progress();
		calcWidth();
	}

	void draw()
	{
		glColor3f(p, p, 1);
		glBegin(GL_QUADS);
			glVertex2f(width, height);
			glVertex2f(width - currWidth, height);
			glVertex2f(halfWidth + 1, halfHeight);
			glVertex2f(halfWidth - 1, halfHeight);
		glEnd();
	}
};

#endif
