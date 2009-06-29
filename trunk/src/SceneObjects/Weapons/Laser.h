#ifndef laser_h
#define laser_h

#include "Weapon.h"
#include "../../Graphics/LaserShotAnimation.h"

class Laser : public Weapon
{
private:
public:
	Laser(LaserShotAnimation* primary) : Weapon(75.f)
	{
		primaryShotAnimation = primary;
	}
};

#endif
