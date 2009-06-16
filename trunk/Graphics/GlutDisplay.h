#ifndef glutdisplay_h
#define glutdisplay_h

#include <string>
#include <sstream>

#include "../SceneObjects/Primitives/Cube.h"
#include "GraphicIncludes.h"

using std::stringstream;
using std::string;

class GlutDisplay
{
private:
	double fieldOfView;
	double screenAspect;
	stringstream ss;
	Cube* cube;


public:
	GlutDisplay();

	static void displayDelegate();
	static void reshapeDelegate(int w, int h);

	void displayFunction()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.5, 0.5, 0.5, 0.0);

		glColor3f(1, 0, 0);
		cube->draw();

		glutSwapBuffers();
	}

	void reshapeFunction(int w, int h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fieldOfView, screenAspect, 0.1, 10);
		gluLookAt(0, 10, 0, 0, -1, 0, 0, 1, 0);
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		glMatrixMode(GL_MODELVIEW);
	}

	void setFOV(string& fov)
	{
		ss << fov;
		ss >> fieldOfView;
		ss.clear();
	}
};

#endif
