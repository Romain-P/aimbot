#ifndef matrix_h
#define matrix_h

#include "Position3.h"

template<class T>
class Matrix
{
private:
	T** values;
	int rows;
	int cols;

public:
	Matrix(int r, int c, T** data) :
		rows(r), cols(c), values(data)
	{
	}

	Matrix(T a, T b, T c,
		   T d, T e, T f,
		   T g, T h, T i)
	{
		values = new T*[r];
		for(int i = 0; i < r; i++)
			values[i] = new T[c];

		rows = 3;
		cols = 3;

		values[0][0] = a;
		values[0][1] = b;
		values[0][2] = c;
		values[1][0] = d;
		values[1][1] = e;
		values[1][2] = f;
		values[2][0] = g;
		values[2][1] = h;
		values[2][2] = i;
	}

	~Matrix()
	{
		for(int i = 0; i < rows; i++)
			delete [] values[i];
		delete [] values;
	}

	Position3 operator*(const Position3& pos)
	{
		if(! (rows == 3 && cols == 3))
			return Position3();
		return Position3(
				values[0][0] * pos.x + values[0][1] * pos.y + values[0][2] * pos.z,
				values[1][0] * pos.x + values[1][1] * pos.y + values[1][2] * pos.z,
				values[2][0] * pos.x + values[2][1] * pos.y + values[2][2] * pos.z);
	}
};

#endif
