#ifndef position3_h
#define position3_h

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

	void operator=(const Position& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
};

#endif
