#include "GlutDisplay.h"

GlutDisplay* glutDisplay;

GlutDisplay::GlutDisplay(Camera* cam) :
	fieldOfView(80),
	camera(cam)
{
	glutDisplay = this;
	screenAspect = double(glutGet(GLUT_SCREEN_WIDTH)) / glutGet(GLUT_SCREEN_HEIGHT);

	cube = new Cube(2.4f);
	box = new Box(1.5f, 2.f, 3.f);
}

void GlutDisplay::displayDelegate()
{
	glutDisplay->displayFunction();
}

void GlutDisplay::reshapeDelegate(int w, int h)
{
	glutDisplay->reshapeFunction(w, h);
}
