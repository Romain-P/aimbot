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

		fore  = StringCaster<char>::cast(ConfigMap::Instance().get("movement.forward"));
		back  = StringCaster<char>::cast(ConfigMap::Instance().get("movement.backward"));
		left  = StringCaster<char>::cast(ConfigMap::Instance().get("movement.left"));
		right = StringCaster<char>::cast(ConfigMap::Instance().get("movement.right"));
		up 	  = StringCaster<char>::cast(ConfigMap::Instance().get("movement.upward"));
		down  = StringCaster<char>::cast(ConfigMap::Instance().get("movement.downward"));
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

	Vector3 getDirection()
	{
		int sum = int(first) + int(second);

		if(sum == fore)				return Vector3( 0, 0,  1);
		else if(sum == left)		return Vector3( 1, 0,  0);
		else if(sum == back) 		return Vector3( 0, 0, -1);
		else if(sum == right)		return Vector3(-1, 0,  0);
		else if(sum == fore + left)	return Vector3( 0.7071f, 0,  0.7071f);
		else if(sum == fore + right)return Vector3(-0.7071f, 0,  0.7071f);
		else if(sum == back + left)	return Vector3( 0.7071f, 0, -0.7071f);
		else if(sum == back + right)return Vector3(-0.7071f, 0, -0.7071f);

		return Vector3(0, 0, 0);
	}
};


#endif
