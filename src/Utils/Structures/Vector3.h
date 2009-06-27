#ifndef vector3
#define vector3

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class Vector3
{
public:
	float x, y, z;

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3(float constant)
	{
		x = constant;
		y = constant;
		z = constant;
	}

	Vector3(Vector3 const& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vector3()
	{
		x = y = z = 0;
	}

	Vector3 cross(Vector3 const& b)
	{
	   Vector3 c(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
	   return c;
	}


	float dot(Vector3 b)
	{
		return x * b.x + y * b.y + z * b.z;
	}


	Vector3 vDot(const Vector3& b)
	{
		return Vector3(x * b.x, y * b.y, z * b.z);
	}

	void normalize()
	{
		double length = this->length();
		if(length < 0.0000001)
			return;
		float scaleFactor = 1.0f / (length);
		*this *= scaleFactor;
	}

	void set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void set(Vector3 & v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vector3 operator-(const Vector3& other)
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 operator+(const Vector3& other)
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 operator*(float value)
	{
		return Vector3(x * value, y * value, z * value);
	}

	void operator+=(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void operator-=(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	void operator*=(float ratio)
	{
		x *= ratio;
		y *= ratio;
		z *= ratio;
	}

	bool operator==(float value)
	{
		return x == value && y == value && z == value;
	}

	//takes care of float roundoff errors
	bool operator==(const Vector3& other)
	{
		return std::abs(x - other.x) < 0.00001f &&
			std::abs(y - other.y) < 0.00001f &&
			std::abs(z - other.z) < 0.00001f;
	}

	float magSqr()
	{
		return x * x + y * y + z * z;
	}

	float length()
	{
		return sqrtf(magSqr());
	}

	/*
	 * Rounded numbers in justified text for easy
	 * reading and debugging
	 */
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
