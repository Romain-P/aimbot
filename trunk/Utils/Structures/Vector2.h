/*
 * Vector2.h
 *
 *  Created on: Jun 16, 2009
 *      Author: Corey
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_


class Vector2
{

public:
	float x, y;

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2(float constant)
	{
		this->x = constant;
		this->y = constant;
	}

	Vector2(Vector2 const& v)
	{
		x = v.x;
		y = v.y;
	}

	Vector2()
	{
		x = y = 0;
	}

	void set(float x, float z)
	{
		this-> x = x;
		this-> y = y;
	}


};


#endif /* VECTOR2_H_ */
