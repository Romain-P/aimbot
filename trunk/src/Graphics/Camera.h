#ifndef camera_h
#define camera_h

#include "Glut/GraphicIncludes.h"
#include "../Physics/Movable.h"
#include "../Utils/Structures/Vector3.h"
#include "../Utils/Structures/Position3.h"

class GlutDisplay;

class Camera
{
private:

	GlutDisplay* display;

public:

	Position3 eye;

	Vector3 up;
	Vector3 look;

	Camera();
	void updateView();
	void setLook(Vector3 look);
	void setEye(const Position3& p);
	void setDisplay(GlutDisplay* display);
};

#endif
