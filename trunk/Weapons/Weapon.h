#ifndef weapon_h
#define weapon_h

class Weapon
{
public:
	float primaryFireDamage;
	float coolDownTime;

	Weapon(float damage) : primaryFireDamage(damage)
	{
		coolDownTime = 1.0f;
	}

	Weapon(float damage, float coolDown) :
		primaryFireDamage(damage),
		coolDownTime(coolDown)
	{
	}

};


#endif
