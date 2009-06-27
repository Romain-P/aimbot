#ifndef orthographicdrawable_h
#define orthographicdrawable_h

#include "Drawable.h"

class Orthographic : public Drawable
{
private:
	bool inOrthoProjection;
	int width;
	int height;

public:
	Orthographic()
	{
		width = glutGet(GLUT_SCREEN_WIDTH);
		height = glutGet(GLUT_SCREEN_HEIGHT);
	}

	Orthographic(int zIndex) : Drawable(zIndex)
	{
		width = glutGet(GLUT_SCREEN_WIDTH);
		height = glutGet(GLUT_SCREEN_HEIGHT);
	}

	virtual void draw() = 0;

	void enterOrthoProjection()
	{
		if(inOrthoProjection)
			return;

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

		inOrthoProjection = true;
	}

	void exitOrthoProjection()
	{
		if(!inOrthoProjection)
			return;

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glDepthMask(GL_TRUE);

		inOrthoProjection = false;
	}
};
#endif
