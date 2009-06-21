#ifndef camera_h
#define camera_h

#include <iostream>

#include "GraphicIncludes.h"
#include "../Utils/Structures/Vector3.h"

class Camera
{
private:

public:
	Vector3 eyeDest, eye, up;
	Vector3 uDest, vDest, nDest;
	Vector3 u, v, n;

	Camera()
	{
		eye = Vector3(0, 2, 0);
		up =  Vector3(0, 1, 0);
		n 	= Vector3(0, 1, 0);
		nDest = n;
		calcUV();
		eyeDest = eye;
	}

	void updateView()
	{
		static float speed = 0.05f;
		eye += (eyeDest - eye) * speed;
		n += (nDest - n) * speed;
		u += (uDest - u) * speed;
		v += (vDest - v) * speed;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, up.x, up.y, up.z);
	}

	void calcUV()
	{
		uDest = Vector3(up.cross(nDest));
		uDest.normalize();
		vDest = Vector3(nDest.cross(uDest));
		vDest.normalize();
	}

    inline void setLookAt()
	{
		gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, up.x, up.y, up.z);
	}
};

#endif
