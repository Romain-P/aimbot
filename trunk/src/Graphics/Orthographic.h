#ifndef orthographicdrawable_h
#define orthographicdrawable_h

#include "Drawable.h"

class Orthographic : public Drawable
{
private:

public:
	Orthographic()
	{
	}

	Orthographic(int zIndex) : Drawable(zIndex)
	{
	}

	static void enterOrthoProjection()
	{
		int width = glutGet(GLUT_SCREEN_HEIGHT);
		int height = glutGet(GLUT_SCREEN_HEIGHT);

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
	}

	static void exitOrthoProjection()
	{
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glDepthMask(GL_TRUE);
	}

	virtual void draw() = 0;
};
#endif
