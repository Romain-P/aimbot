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

	Camera* camera;

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
		glClearColor(0.1, 0.16, 0.26, 0);
		glMatrixMode(GL_MODELVIEW);

		static vector<Drawable*>::const_iterator it;
		for(it = drawables.begin(); it != drawables.end(); ++it)
		{
			(*it)->draw();
		}

		glFlush();
		glutSwapBuffers();
	}

	void reshapeFunction(int w, int h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fieldOfView, screenAspect, 0.01, 1000);
		camera->updateView();
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		glMatrixMode(GL_MODELVIEW);
	}

	void updateCamera()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(fieldOfView, screenAspect, 0.01, 1000);
		camera->updateView();
		glMatrixMode(GL_MODELVIEW);
	}

	void addDrawable(Drawable* drawable)
	{
		drawables.push_back(drawable);

		sort(drawables.begin(), drawables.end(), zSort);
	}

	void setFOV(float fov)
	{
		fieldOfView = fov;
	}

	float getFOV()
	{
		return fieldOfView;
	}

	float getGamma()
	{
		return gamma;
	}

	double getScreenAspect()
	{
		return screenAspect;
	}

	static bool zSort(Drawable* a, Drawable* b)
	{
		return a->zIndex > b->zIndex;
	}
};

#endif
