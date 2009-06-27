#ifndef projectileweapon_h
#define projectileweapon_h

#include "Weapon.h"

class ProjectileWeapon : public Weapon
{
public:
	float primaryFireDamage;
	float initialSpeed;
	float acceleration;

	float splashRadius;
	float splashFalloff;
	float splashDamage;

	Vector3 shotAngle;

	ProjectileWeapon(float primaryFireDamage,
			float initialSpeed,
			float acceleration,
			float splashRadius,
			float splashFalloff,
			float splashDamage) : Weapon(primaryFireDamage)
	{
		this->initialSpeed = initialSpeed;
		this->acceleration = acceleration;
		this->splashRadius = splashRadius;
		this->splashFalloff = splashFalloff;
		this->splashDamage = splashDamage;
	}
};

#endif
