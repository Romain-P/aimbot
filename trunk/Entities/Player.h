#ifndef player_h
#define player_h

#include <iostream>
#include <vector>

#include "../Utils/Vector3.h"
#include "../Utils/Position3.h"
#include "../Weapons/Weapon.h"
#include "../Meshes/Mesh.h"
#include "../Meshes/Hitbox.h"


using namespace std;

class Player
{
private:
	string name;
	float health;

	vector<Weapon*> weapons;

	Position3 position;
	Vector3 lookDirection;
	Vector3 velocity;

	Mesh* playerMesh;
	Hitbox* hitbox;

public:
	Player(string name)
	{
		this->name = name;
		health = 100;

		playerMesh = new Mesh();
		initializeMesh();

		//the hitbox adapt to a given mesh
		hitbox = new Hitbox(playerMesh);
	}

	void initializeMesh()
	{
		//do it
	}


	string getName()
	{
		return name;
	}

	float getHealth()
	{
		return health;
	}

	vector<Weapon*>& getWeapons()
	{
		return weapons;
	}

	Position3 getPosition()
	{
		return position;
	}

	Vector3 getLookDirection()
	{
		return lookDirection;
	}

	Vector3 getMovement()
	{
		return movement;
	}

	//Set methods
	void setName(string n)
	{
		name = n;
	}

	void setHealth(float h)
	{
		health = h;
	}

	void addWeapon(Weapon* weapon)
	{
		weapons.add(weapon);
	}

	void setPosition(Position3 p)
	{
		position = p;
	}

	void setLookDirection(Vector3 l)
	{
		lookDirection = l;
	}

	void setVelocity(Vector3 v)
	{
		velocity = v;
	}

};


#endif
