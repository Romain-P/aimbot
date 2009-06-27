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
	float theta;
	float phi;

	Vector3 up;
	Vector3 look;

	Camera();
	void updateView();
	void calcLook(float, float);
	void calcUV();
	void setDisplay(GlutDisplay* display);
	void updateVelocity(const Vector3&);
};

#endif
