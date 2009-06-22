#include "GlutDisplay.h"

GlutDisplay* glutDisplay;

GlutDisplay::GlutDisplay(Camera* cam) :
	fieldOfView(80),
	camera(cam)
{
	glutDisplay = this;
	screenAspect = double(glutGet(GLUT_SCREEN_WIDTH)) / glutGet(GLUT_SCREEN_HEIGHT);

	camera->updateView();
}

void GlutDisplay::initGraphicsOptions()
{
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLineWidth(1.0);
	glPointSize(2.0);
	glDepthMask(GL_FALSE);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.1, 0.16, 0.26, 0);
}

void GlutDisplay::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	static vector<Drawable*>::const_iterator it;
	for(it = drawables.begin(); it != drawables.end(); ++it)
	{
		(*it)->draw();
	}

	glFlush();
	glutSwapBuffers();
}

void GlutDisplay::reshapeFunction(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fieldOfView, screenAspect, 0.01, 1000);
	camera->updateView();
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_MODELVIEW);
}

void GlutDisplay::updateCamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fieldOfView, screenAspect, 0.01, 1000);
	camera->updateView();
	glMatrixMode(GL_MODELVIEW);
}

void GlutDisplay::addDrawable(Drawable* drawable)
{
	drawables.push_back(drawable);

	sort(drawables.begin(), drawables.end(), zSort);
}

void GlutDisplay::setFOV(float fov)
{
	fieldOfView = fov;
}

float GlutDisplay::getFOV()
{
	return fieldOfView;
}

float GlutDisplay::getGamma()
{
	return gamma;
}

double GlutDisplay::getScreenAspect()
{
	return screenAspect;
}

bool GlutDisplay::zSort(Drawable* a, Drawable* b)
{
	return a->zIndex > b->zIndex;
}

void GlutDisplay::displayDelegate()
{
	glutDisplay->displayFunction();
}

void GlutDisplay::reshapeDelegate(int w, int h)
{
	glutDisplay->reshapeFunction(w, h);
}
