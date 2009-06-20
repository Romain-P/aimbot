#ifndef glutdisplay_h
#define glutdisplay_h

#include <string>
#include <sstream>
#include <vector>

#include "MeshRenderer.h"
#include "GraphicIncludes.h"
#include "Drawable.h"
#include "Camera.h"

#include "HUD/PlayerHUD.h"
#include "HUD/DevConsole.h"

#include "../SceneObjects/Primitives/Cube.h"
#include "../SceneObjects/Primitives/Box.h"

using std::stringstream;
using std::string;
using std::vector;

class GlutDisplay
{
private:
	float gamma;
	double fieldOfView;
	double screenAspect;

	stringstream ss;
	vector<Drawable*> drawables;

	Box* box;
	Cube* cube;

	Camera* camera;
	DevConsole* console;
	PlayerHUD* hud;

public:
	GlutDisplay(Camera* cam);

	static void displayDelegate();
	static void reshapeDelegate(int w, int h);

	void initGraphicsOptions()
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
	}

	void displayFunction()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.9, 0.2, 0.2, 0.0);

		for(unsigned int i = 0; i < drawables.size(); i++)
		{
			drawables.at(i)->draw();
		}

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
		camera->updateView();
	}

	void addDrawable(Drawable* drawable)
	{
		drawables.push_back(drawable);

		//sort by z-index?
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
