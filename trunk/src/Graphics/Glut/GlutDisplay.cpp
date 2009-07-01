#include "GlutDisplay.h"
#include "GlutLighting.h"

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
	//glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLineWidth(2.0);
	glPointSize(2.0);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1, 0.16, 0.26, 0);
	glutSetCursor(GLUT_CURSOR_NONE);
	glPushAttrib (GL_ALL_ATTRIB_BITS);

	GlutLighting::initLight();
}

void GlutDisplay::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	static vector<Drawable*>::const_iterator drawIter;
	static vector<Drawable*>::const_iterator orthoIter;

	for(drawIter = drawables.begin(); drawIter != drawables.end(); ++drawIter)
	{
		(*drawIter)->draw();
	}

	enterOrthoProjection();
	for(orthoIter = orthographics.begin(); orthoIter != orthographics.end(); ++orthoIter)
		(*orthoIter)->draw();
	exitOrthoProjection();

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
	glLoadIdentity();
	gluPerspective(fieldOfView, screenAspect, 0.01, 1000);
	camera->updateView();
}

void GlutDisplay::addDrawable(Drawable* drawable)
{
	drawables.push_back(drawable);
	sort(drawables.begin(), drawables.end(), zSort);
}

void GlutDisplay::addOrthographic(Drawable* drawable)
{
	orthographics.push_back(drawable);
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

void GlutDisplay::enterOrthoProjection()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	// fix blending problems with overlapping lines
	glDepthMask(GL_FALSE);

	// save current projection matrix
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	// switch to orthographic projection
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	// back to modelview to scale / translate
	glMatrixMode(GL_MODELVIEW);

	glScalef(1, -1, 1);
	glTranslatef(0, -height, 0);

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1.0);
}

void GlutDisplay::exitOrthoProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glDisable(GL_LINE_SMOOTH);
	glLineWidth(2.0);
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
