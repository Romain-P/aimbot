#ifndef glutdisplay_h
#define glutdisplay_h

#include "GraphicIncludes.h"

class GlutDisplay
{
private:
	double fieldOfView;
	double screenAspect;

public:
	GlutDisplay();

	static void displayDelegate();
	static void reshapeDelegate(int w, int h);

	void displayFunction()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.5, 0.5, 0.5, 0.0);

		glutSwapBuffers();
	}

	void reshapeFunction(int w, int h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fieldOfView, screenAspect, 0.1, 10);
		gluLookAt(0, 0, 2, 0, 0, 1, 0, 1, 0);
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		glMatrixMode(GL_MODELVIEW);
	}
};

#endif
