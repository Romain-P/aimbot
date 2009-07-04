#ifndef lasershotanimation_h
#define lasershotanimation_h

#include "Animatable.h"
#include "AnimationStage.h"
#include "../Utils/Math/Random.h"

class ChargeUpStage : public AnimationStage
{
private:
	float r, g, b;
public:
	ChargeUpStage(float duration) :
		AnimationStage(duration), r(0), g(0), b(0)
	{
	}

	void draw()
	{
		glColor3f(r, g, b);
		glBegin(GL_QUADS);
			glVertex2f(0, 100);
			glVertex2f(100, 100);
			glVertex2f(100, 0);
			glVertex2f(0, 0);
		glEnd();
	}
	void animate()
	{
		r = 1 - progress();
		g = r;
		b = r;
	}
};

class SustainStage : public AnimationStage
{
private:
	float r, g, b;
public:
	SustainStage(float duration) :
		AnimationStage(duration), r(0), g(0), b(0)
	{
	}

	void draw()
	{
		glColor3f(r, g, b);
		glBegin(GL_QUADS);
			glVertex2f(0, 100);
			glVertex2f(100, 100);
			glVertex2f(100, 0);
			glVertex2f(0, 0);
		glEnd();
	}

	void animate()
	{
		r = fmodf(timeElapsed, 0.3f);
		g = fmodf(timeElapsed, 0.4f);
		b = fmodf(timeElapsed, 1.2f);
	}
};

class CooldownStage : public AnimationStage
{
private:
	float r, g, b;
public:
	CooldownStage(float duration) :
		AnimationStage(duration), r(0), g(0), b(0)
	{
	}

	void draw()
	{
		glColor3f(r, g, b);
		glBegin(GL_QUADS);
			glVertex2f(0, 100);
			glVertex2f(100, 100);
			glVertex2f(100, 0);
			glVertex2f(0, 0);
		glEnd();
	}
	void animate()
	{
		b = progress();
		r = b;
		g = b;
	}
};

class LaserShotAnimation : public Animatable
{
private:
	float baseWidth;
	float currWidth;
	float p;

public:
	LaserShotAnimation()
	{
		baseWidth = 20.f;
		currWidth = 1.f;

		stages.push_back(new ChargeUpStage(0.6f));
		stages.push_back(new SustainStage(AnimationStage::INFINITE_TIME));
		stages.push_back(new CooldownStage(0.6f));

	}
};

#endif
