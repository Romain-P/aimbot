#ifndef weapon_h
#define weapon_h

#include "../../Graphics/Animation/Animatable.h"
#include "../../Utils/Misc/MicroTimer.h"

class Weapon
{
protected:
	Animatable* primaryShotAnimation;
	Animatable* secondaryShotAnimation;

	float primaryFireDamage;
	float secondaryFireDamage;
	float coolDownTime;
	int releaseStage;

	MicroTimer timer;

public:

	Weapon(float damage, int release) :
		primaryFireDamage(damage),
		releaseStage(release)
	{
		coolDownTime = 1.0f;
		timer.start();
	}

	Weapon(float damage, float coolDown, int release) :
		primaryFireDamage(damage),
		coolDownTime(coolDown),
		releaseStage(release)
	{
		timer.start();
	}

	//TODO: solve the problem of not being able to shoot when
	//		game loads, before a period of 'cooldowntime' has passed
	void firePrimary()
	{
		timer.stop();
		if(timer.delta() > coolDownTime || true)
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
		primaryShotAnimation->setStage(releaseStage);
	}

	void releaseSecondary()
	{
		primaryShotAnimation->expireStage();
	}
};


#endif
