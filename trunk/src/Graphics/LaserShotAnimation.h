#ifndef lasershotanimation_h
#define lasershotanimation_h

#include "Animatable.h"
#include "../Utils/Math/Random.h"

class ChargeUpStage: public AnimationStage
{
public:
	ChargeUpStage(float duration) :
		AnimationStage(duration)
	{
	}

	void draw()
	{
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
	void animate()
	{
		p = progress();
		calcWidth();
	}
};

class SustainStage: public AnimationStage
{
public:
	SustainStage(float duration) :
		AnimationStage(duration)
	{
	}

	void draw()
	{
		if (!animating)
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
	void animate()
	{
		p = progress();
		calcWidth();
	}
};

class CooldownStage: public AnimationStage
{
public:
	CooldownStage(float duration) :
		AnimationStage(duration)
	{
	}

	void draw()
	{
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
	void animate()
	{
		p = progress();
		calcWidth();
	}
};

class LaserShotAnimation: public Animatable
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
	LaserShotAnimation()
	{
		baseWidth = 20.f;
		currWidth = 1.f;

		stages.push_back(ChargeUpStage(0.2f));
		stages.push_back(SustainStage(AnimationStage::INFINITE_TIME));
		stages.push_back(CooldownStage(0.2f));
	}
};

#endif
