#include "GlutDisplay.h"

GlutDisplay* glutDisplay;

GlutDisplay::GlutDisplay()
{
	glutDisplay = this;

	screenAspect = double(glutGet(GLUT_SCREEN_WIDTH)) / glutGet(GLUT_SCREEN_HEIGHT);
	fieldOfView = 80;
}

void GlutDisplay::displayDelegate()
{
	glutDisplay->displayFunction();
}

void GlutDisplay::reshapeDelegate(int w, int h)
{
	glutDisplay->reshapeFunction(w, h);
}
