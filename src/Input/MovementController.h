#ifndef movementcontrols_h
#define movementcontrols_h

#include "ConfigMap.h"
#include "../Utils/Structures/Vector3.h"
#include "../Utils/Misc/StringCaster.h"

/*
 * We remember the most recent two movement keys
 * that were pressed, and move in their direction.
 * FIXME: three buttons down, then one released produces undesired direction
 */

class MovementController
{
private:
	char getConfigKey(const string& key)
	{
		string value = ConfigMap::Instance().get(key);

		if(value == "ctrl")			return 19;
		else if(value == "space")	return ' ';

		return value[0];
	}

protected:
	char fore, back, left, right, up, down;
	int oppoH, oppoV;

	char first;		// last pressed key
	char second;	// second last pressed key
public:

	MovementController()
	{
		first = 0;
		second = 0;

		fore  = getConfigKey("movement.forward");
		back  = getConfigKey("movement.backward");
		left  = getConfigKey("movement.left");
		right = getConfigKey("movement.right");
		up 	  = getConfigKey("movement.upward");
		down  = getConfigKey("movement.downward");
	}

	void push(char ch)
	{
		if(ch != first)
		{
			second = first;
			first = ch;
			if(first + second == oppoH || first + second == oppoH)
			{
				second = 0;
			}
		}
	}

	void pop(char ch)
	{
		if(ch == first)
		{
			first = second;
			second = 0;
		}
		else if(ch == second)
		{
			second = 0;
		}
	}

	Vector3 getVelocity()
	{
		int sum = int(first) + int(second);

		     if(sum == fore)		return Vector3( 0,  0,  1);
		else if(sum == left)		return Vector3( 1,  0,  0);
		else if(sum == back) 		return Vector3( 0,  0, -1);
		else if(sum == right)		return Vector3(-1,  0,  0);
		else if(sum == up)			return Vector3( 0,  1,  0);
		else if(sum == down)		return Vector3( 0, -1,  0);

		else if(sum == fore + left)	return Vector3( 0.7071f, 0, 0.7071f);
		else if(sum == fore + right)return Vector3(-0.7071f, 0, 0.7071f);
		else if(sum == back + left)	return Vector3( 0.7071f, 0,-0.7071f);
		else if(sum == back + right)return Vector3(-0.7071f, 0,-0.7071f);

		return Vector3(0, 0, 0);
	}
};


#endif
