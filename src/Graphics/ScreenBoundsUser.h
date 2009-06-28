#ifndef screenboundsuser_h
#define screenboundsuser_h

#include "GraphicIncludes.h"

class ScreenBoundsUser
{
protected:
	int topLeftX;
	int topLeftY;
	int width;
	int height;
	int halfWidth;
	int halfHeight;

	ScreenBoundsUser()
	{
		topLeftX = glutGet(GLUT_WINDOW_X);
		topLeftY = glutGet(GLUT_WINDOW_Y);
		width = glutGet(GLUT_SCREEN_WIDTH);
		height = glutGet(GLUT_SCREEN_HEIGHT);

		halfWidth = width / 2;
		halfHeight = height / 2;
	}
};


#endif
