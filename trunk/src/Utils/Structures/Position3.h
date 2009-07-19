#ifndef position3_h
#define position3_h

#include "Vector3.h"

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

	Position3(const Position3& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	void operator=(const Position3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	Position3 operator*(const float value)
	{
		return Position3(x * value, y * value, z * value);
	}

	const Position3 operator+(const Position3& other)
	{
		return Position3(x + other.x, y + other.y, z + other.z);
	}

	/* for physical operations, like d = v·dt */
	void operator+=(const Vector3& vect)
	{
		x += vect.x;
		y += vect.y;
		z += vect.z;
	}

	void operator+=(const Position3& pos)
	{
		x += pos.x;
		y += pos.y;
		z += pos.z;
	}

	void operator*=(float ratio)
	{
		x *= ratio;
		y *= ratio;
		z *= ratio;
	}

	float operator[](int index) const
	{
		switch(index) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		}
	}

	float dist(const Position3& point) const
	{
		return sqrtf(dist2(point));
	}

	float dist2(const Position3& point) const
	{
		return (x - point.x) * (x - point.x) +
			   (y - point.y) * (y - point.y) +
			   (z - point.z) * (z - point.z);
	}

	std::string print()
	{
		char buf[30];
		sprintf(buf, "%3.3f %3.3f %3.3f", x, y, z);
		return std::string(buf);
	}
};

#endif
