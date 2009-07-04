#ifndef laser_h
#define laser_h

#include "Weapon.h"
#include "../../Graphics/Animation/LaserShotAnimation.h"

class Laser : public Weapon
{
private:
public:
	Laser(LaserShotAnimation* primary) : Weapon(75.f)
	{
		primaryShotAnimation = primary;
		secondaryShotAnimation = primary;
	}
};

#endif
