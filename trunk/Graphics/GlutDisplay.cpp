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
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1, 0.16, 0.26, 0);
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}

void GlutDisplay::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	static vector<Drawable*>::const_iterator drawIter;
	static vector<OrthographicDrawable*>::const_iterator orthoIter;

	for(drawIter = drawables.begin(); drawIter != drawables.end(); ++drawIter)
	{
		(*drawIter)->draw();
	}

	for(orthoIter = orthographics.begin(); orthoIter != orthographics.end(); ++orthoIter)
	{
		(*orthoIter)->draw();
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
	//glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fieldOfView, screenAspect, 0.01, 1000);
	camera->updateView();
	//glMatrixMode(GL_MODELVIEW);
}

void GlutDisplay::addDrawable(Drawable* drawable)
{
	drawables.push_back(drawable);
	sort(drawables.begin(), drawables.end(), zSort);
}

void GlutDisplay::addOrthographic(Orthographic* orthographic)
{
	orthographics.push_back(orthographic);
	sort(orthographics.begin(), orthographics.end(), zSort);
}

void GlutDisplay::removeDrawable(Drawable* drawable)
{
	vector<Drawable*>::iterator it = drawables.begin();
	while(*it != drawable && it != drawables.end())
		++it;

	if(*it == drawable)
		drawables.erase(it);
}

void GlutDisplay::removeOrthographic(Orthographic* orthographic)
{
	vector<Orthographic*>::iterator it = orthographics.begin();
	while(*it != orthographic && it != orthographics.end())
		++it;

	if(*it == orthographic)
		orthographics.erase(it);
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
