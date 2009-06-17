#ifndef glutdisplay_h
#define glutdisplay_h

#include <string>
#include <sstream>

#include "../SceneObjects/Primitives/Cube.h"
#include "MeshRenderer.h"
#include "GraphicIncludes.h"
#include "Camera.h"

using std::stringstream;
using std::string;

class GlutDisplay
{
private:
	double fieldOfView;
	double screenAspect;
	float gamma;
	stringstream ss;
	Cube* cube;
	Camera* camera;

public:
	GlutDisplay();

	static void displayDelegate();
	static void reshapeDelegate(int w, int h);

	void displayFunction()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.5, 0.5, 0.5, 0.0);

		glColor3f(1, 0, 0);
		MeshRenderer::draw(cube);

		glutSwapBuffers();
	}

	void reshapeFunction(int w, int h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fieldOfView, screenAspect, 0.1, 10);
		camera->setLookAt();
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		glMatrixMode(GL_MODELVIEW);
	}

	void updateCamera()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fieldOfView, screenAspect, 0.1, 10);
		camera->setLookAt();
	}

	void setFOV(string& fov)
	{
		ss << fov;
		ss >> fieldOfView;
		ss.clear();
	}

	float getGamma()
	{
		return gamma;
	}
};

#endif
