#ifndef player_h
#define player_h

#include <vector>

#include "Entity.h"
#include "../Weapons/Weapon.h"
#include "../Mesh.h"
#include "Hitbox.h"

class Player : public Entity
{
private:
	float health;

	std::vector<Weapon*> weapons;
	Mesh* playerMesh;
	Hitbox* hitbox;

	void initializeMesh()
	{
		//do it
	}

public:
	Player(string name) : Entity(name)
	{
		health = 100;

		playerMesh = new Mesh();
		initializeMesh();

		//the hitbox adapt to a given mesh
		hitbox = new Hitbox(playerMesh);
	}

	void addWeapon(Weapon* weapon)
	{
		weapons.add(weapon);
	}

	std::vector<Weapon*>& getWeapons()
	{
		return weapons;
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
