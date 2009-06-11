/*
 * Position3.h
 *
 *  Created on: Jun 10, 2009
 *      Author: Corey
 */

#ifndef Position3d
#define Position3d

class Position3
{
public:
	float x, y, z;

	Position3()
	{
		x = y = z = 0;
	}
	Position3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


};

#endif
