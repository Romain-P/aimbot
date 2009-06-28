#ifndef colour_h
#define colour_h

class Colour
{
private:
public:
	float r;
	float g;
	float b;

	Colour()
	{
		r = g = b = 0;
	}

	Colour(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

	Colour operator+(const Colour& other)
	{
		return Colour(r + other.r, g + other.g, b + other.b);
	}

	void operator=(const Colour& other)
	{
		r = other.r;
		g = other.g;
		b = other.b;
	}
};

#endif
