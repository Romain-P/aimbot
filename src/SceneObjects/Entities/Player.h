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
	}

	~Player()
	{
		delete mesh;
		delete hitbox;
	}

	void addWeapon(Weapon* weapon)
	{
		weapons.push_back(weapon);
	}

	void setHealth(float h)
	{
		health = h;
	}

	float getHealth()
	{
		return health;
	}

};


#endif
