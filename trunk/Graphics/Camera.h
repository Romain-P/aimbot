#ifndef camera_h
#define camera_h

#include <iostream>

#include "GraphicIncludes.h"
#include "../Utils/Structures/Vector3.h"
#include "../Physics/Movable.h"

class GlutDisplay;

class Camera : public Movable
{
private:
	GlutDisplay* display;

public:
	Vector3 eyeDest, eye, up;
	Vector3 uDest, vDest, nDest;
	Vector3 u, v, n;

	Camera();
	void updateView();
	void calcUV();
	void setDisplay(GlutDisplay* display);
    void setLookAt();
};

#endif
