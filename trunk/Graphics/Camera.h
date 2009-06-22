#ifndef camera_h
#define camera_h

#include "GraphicIncludes.h"
#include "../Utils/Structures/Vector3.h"
#include "../Physics/Movable.h"

class GlutDisplay;

class Camera : public Movable
{
private:
	GlutDisplay* display;

public:
	Vector3 eyeDest, up;
	Vector3 uDest, vDest, nDest;
	Vector3 u, v, n;

	Camera();
	void updateView();
	void calcUV();
	void setDisplay(GlutDisplay* display);
};

#endif
