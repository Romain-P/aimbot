#ifndef weapon_h
#define weapon_h

#include "../../Graphics/Animatable.h"
#include "../../Utils/Misc/MicroTimer.h"

class Weapon
{
protected:
	Animatable* primaryShotAnimation;
	Animatable* secondaryShotAnimation;

	float primaryFireDamage;
	float secondaryFireDamage;
	float coolDownTime;

	MicroTimer timer;

public:

	Weapon(float damage) : primaryFireDamage(damage)
	{
		coolDownTime = 1.0f;
		timer.startMicroTimer();
	}

	Weapon(float damage, float coolDown) :
		primaryFireDamage(damage),
		coolDownTime(coolDown)
	{
		timer.startMicroTimer();
	}

	void firePrimary()
	{
		timer.stop();

		if(timer.delta() > coolDownTime)
			primaryShotAnimation->startAnimation();

		timer.start();
	}

	void fireSecondary()
	{
		timer.stop();

		if(timer.delta() > coolDownTime)
			secondaryShotAnimation->startAnimation();

		timer.start();
	}

	void releasePrimary()
	{
		primaryShotAnimation->expireStage();
	}

	void releaseSecondary()
	{
		primaryShotAnimation->expireStage();
	}
};


#endif
