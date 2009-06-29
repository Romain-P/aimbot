#ifndef weapon_h
#define weapon_h

#include "../../Graphics/Animatable.h"

class Weapon
{
protected:
	Animatable* primaryShotAnimation;
	Animatable* secondaryShotAnimation;

	float primaryFireDamage;
	float secondaryFireDamage;
	float coolDownTime;

public:

	Weapon(float damage) : primaryFireDamage(damage)
	{
		coolDownTime = 1.0f;
		primaryShotAnimation = NULL;
		secondaryShotAnimation = NULL;
	}

	Weapon(float damage, float coolDown) :
		primaryFireDamage(damage),
		coolDownTime(coolDown)
	{
		primaryShotAnimation = NULL;
		secondaryShotAnimation = NULL;
	}

	void firePrimary()
	{
		if(primaryShotAnimation != NULL)
			primaryShotAnimation->startAnimation();
	}

	void fireSecondary()
	{
		if(secondaryShotAnimation != NULL)
			secondaryShotAnimation->startAnimation();
	}
};


#endif
