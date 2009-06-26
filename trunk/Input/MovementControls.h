#ifndef movementcontrols_h
#define movementcontrols_h

#include "ConfigMap.h"
#include "../Utils/Structures/Vector3.h"

// TODO: use the configmap to assign movement keys to user's bindings

/*
 * We remember the most recent two movement keys
 * that were pressed, and move in their direction.
 */

class MovementControls
{
public:
	enum movements
	{
		FORWARD 	= 'w',
		LEFT 		= 'a',
		BACKWARD 	= 's',
		RIGHT 		= 'd',
		UP			= ' ',
		DOWN
	};

	enum opposites
	{
		OPPO_H	= 'a' + 'd',
		OPPO_V	= 'w' + 's'
	};


	char first;		// last pressed key
	char second;	// second last pressed key

	MovementControls()
	{
		first = 0;
		second = 0;
	}

	void push(char ch)
	{
		if(ch != first)
		{
			second = first;
			first = ch;
			if(first + second == OPPO_H || first + second == OPPO_V)
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

		switch(sum)
		{
		case FORWARD: 			return Vector3( 0, 0,  1);
		case LEFT: 				return Vector3( 1, 0,  0);
		case BACKWARD: 			return Vector3( 0, 0, -1);
		case RIGHT: 			return Vector3(-1, 0,  0);
		case FORWARD + LEFT: 	return Vector3( 0.7071f, 0,  0.7071f);
		case FORWARD + RIGHT: 	return Vector3(-0.7071f, 0,  0.7071f);
		case BACKWARD + LEFT: 	return Vector3( 0.7071f, 0, -0.7071f);
		case BACKWARD + RIGHT: 	return Vector3(-0.7071f, 0, -0.7071f);

		}

		return Vector3(0, 0, 0);
	}
};


#endif
