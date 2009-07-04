#ifndef player_h
#define player_h

#include <vector>

#include "Entity.h"
#include "../Hitbox.h"
#include "../Weapons/Weapon.h"
#include "../Mesh.h"

using std::vector;

class Player : public Entity
{
private:
	float health;

	vector<Weapon*> weapons;
	Weapon* currentWeapon;
	Mesh* mesh;
	Hitbox* hitbox;

	void initializeMesh()
	{
		//do it
	}

public:
	Player() : Entity("")
	{
		health = 100;
		currentWeapon = NULL;
	}

	~Player()
	{

		//delete mesh;
		//delete hitbox;
	}

	void addWeapon(Weapon* weapon)
	{
		weapons.push_back(weapon);
		currentWeapon = weapon;
	}

	void setHealth(float h)
	{
		health = h;
	}

	float getHealth()
	{
		return health;
	}

	void firePrimary()
	{
		if(currentWeapon != NULL)
			currentWeapon->firePrimary();
		else
			std::cout << "weapon is null" << std::endl;
	}

	void fireSecondary()
	{
		if(currentWeapon != NULL)
			currentWeapon->fireSecondary();
	}

	void releasePrimary()
	{
		if(currentWeapon != NULL)
			currentWeapon->releasePrimary();
	}

	void releaseSecondary()
	{

	}
};


#endif