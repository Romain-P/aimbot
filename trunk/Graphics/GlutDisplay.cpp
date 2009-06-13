#include "GlutDisplay.h"

GlutDisplay* glutDisplay;

GlutDisplay::GlutDisplay()
{
	glutDisplay = this;

	screenAspect = double(glutGet(GLUT_SCREEN_WIDTH)) / glutGet(GLUT_SCREEN_HEIGHT);
	fieldOfView = 80;
}

inline void GlutDisplay::displayDelegate()
{
	glutDisplay->displayFunction();
}

inline ovid GlutDisplay::reshapeDelegate(int w, int h)
{
	glutDisplay->reshapeFunction(w, h);
}
