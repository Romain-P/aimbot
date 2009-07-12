#ifndef laser_h
#define laser_h

#include "Weapon.h"
#include "../../Graphics/Animation/LaserShotAnimation.h"

class Laser : public Weapon
{
private:
public:
	Laser() : Weapon(75.f, 2)
	{
		primaryShotAnimation = new LaserShotAnimation();
		//secondaryShotAnimation = primaryShotAnimation;
	}

	~Laser()
	{
		delete primaryShotAnimation;
	}
};

#endif
