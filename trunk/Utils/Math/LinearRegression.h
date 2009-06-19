#ifndef linearregression_h
#define linearregression_h

#include <vector>
#include <utility>

using namespace std;

class Line
{
	float slope;
	float intercept;
};

class LinearRegression
{
	static Line* getRegression(vector<pair<float, float>>* input)
	{
		Line* line = new Line();


	}


	/*
	y = b1*x + b0
	b1 = sum((x_i-x_avg)*(y_i-y_avg)) / sum((x_i-x_avg)^2)
	b0 = y_avg - b1*x_avg
	*/
};

#endif
