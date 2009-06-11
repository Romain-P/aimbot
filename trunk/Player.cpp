/*
 * Player.cpp
 *
 *  Created on: Jun 10, 2009
 *      Author: Corey
 */

#include "Player.h"
using namespace std;

class Player
{

private:

	string name;
	int health;
	// Change weapons array to a weapon type when created
	string** weapons = new string*[10];
	Position3 position;
	Vector3 look;
	Vector3 movement;

public:

	Player()
	{

	}

	//Get methods, bitches
	string getName()
	{
		return name;
	}

	int getHealth()
	{
		return health;
	}

	string* getWeapons()
	{
		return weapons;
	}

	Position3 getPosition()
	{
		return position;
	}

	Vector3 getLook()
	{
		return look;
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

	void setHealth(int h)
	{
		health = h;
	}

	void setWeapons(string w [])
	{

	}

	void setPosition(Position3 p)
	{
		position = p;
	}

	void setLook(Vector3 l)
	{
		look = l;
	}

	void setMovement(Vector3 m)
	{
		movement = m;
	}

};
