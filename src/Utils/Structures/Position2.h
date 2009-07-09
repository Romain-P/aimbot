#ifndef position2_h
#define position2_h

class Position2
{
public:
	float x;
	float y;

	Position2()
	{
		x = 0;
		y = 0;
	}

	Position2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Position2(const Position2& other)
	{
		x = other.x;
		y = other.y;
	}

	std::string print()
	{
		char buff[20];
		sprintf(buff, "%3.3f %3.3f", x, y);
		return std::string(buff);
	}
};

#endif
