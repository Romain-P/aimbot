#ifndef glutdisplay_h
#define glutdisplay_h

#include <string>
#include <sstream>
#include <vector>

#include "GraphicIncludes.h"
#include "../MeshRenderer.h"
#include "../Drawable.h"
#include "../Camera.h"
#include "../HUD/PlayerHUD.h"
#include "../HUD/DevConsole.h"

using std::stringstream;
using std::string;
using std::vector;


class GlutDisplay : public ScreenBoundsUser
{
private:
	float gamma;
	double fieldOfView;
	double screenAspect;

	stringstream ss;

	vector<Drawable*> drawables;
	vector<Drawable*> orthographics;

	Camera* camera;

public:
	GlutDisplay(Camera* cam);

	void initGraphicsOptions();
	void displayFunction();
	void reshapeFunction(int w, int h);
	void updateCamera();
	void addDrawable(Drawable* drawable);
	void addOrthographic(Drawable* drawable);
	void removeDrawable(Drawable* drawable);
	void enterOrthoProjection();
	void exitOrthoProjection();

	void setFOV(float fov);
	float getFOV();
	float getGamma();
	double getScreenAspect();

	static bool zSort(Drawable* a, Drawable* b);
	static void displayDelegate();
	static void reshapeDelegate(int w, int h);
};

#endif
