#ifndef orthographicdrawable_h
#define orthographicdrawable_h

#include "Drawable.h"

class OrthographicDrawable : public Drawable
{
private:
	bool inOrthoProjection;

public:
	OrthographicDrawable(int zIndex) : Drawable(zIndex)
	{

	}

	virtual void draw() = 0;

	void orthoDraw()
	{
		enterOrthoProjection();
		draw();
		exitOrthoProjection();
	}

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
		gluOrtho2D(0, glutGet(GLUT_SCREEN_WIDTH), 0, glutGet(GLUT_SCREEN_HEIGHT));

		// back to modelview to scale / translate
		glMatrixMode(GL_MODELVIEW);

		glScalef(1, -1, 1);
		glTranslatef(0, -glutGet(GLUT_SCREEN_HEIGHT), 0);

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
