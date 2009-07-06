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

	void operator=(const Position3& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
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


	std::string print()
	{
		float nums[] =
		{
			int(1000*x)/1000.f,
			int(1000*y)/1000.f,
			int(1000*z)/1000.f
		};

		std::string s[3];
		std::string final = "";
		std::stringstream ss;

		for(int i = 0; i < 3; i++)
		{
			ss << nums[i];
			ss >> s[i];
			ss.clear();
			final += nums[i] < 0 ? "" : " ";
			final += s[i];
			for(unsigned int j = 0; j < 8 - (s[i].length() - int(nums[i] < 0)); j++)
				final += " ";
		}
		return final;
	}
};

#endif
