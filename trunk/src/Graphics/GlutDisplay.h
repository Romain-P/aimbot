#ifndef glutdisplay_h
#define glutdisplay_h

#include <string>
#include <sstream>
#include <vector>

#include "MeshRenderer.h"
#include "GraphicIncludes.h"
#include "Drawable.h"
#include "Orthographic.h"
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

	// all 3D renderable objects in scene
	vector<Drawable*> drawables;

	// all 2D renderable objects
	vector<Orthographic*> orthographics;

	Camera* camera;

public:
	GlutDisplay(Camera* cam);

	void initGraphicsOptions();
	void displayFunction();
	void reshapeFunction(int w, int h);
	void updateCamera();
	void addDrawable(Drawable* drawable);
	void addOrthographic(Orthographic* drawable);
	void removeDrawable(Drawable* drawable);
	void removeOrthographic(Orthographic* drawable);

	void setFOV(float fov);

	float getFOV();
	float getGamma();
	double getScreenAspect();

	static bool zSort(Drawable* a, Drawable* b);

	static void displayDelegate();
	static void reshapeDelegate(int w, int h);
};

#endif
