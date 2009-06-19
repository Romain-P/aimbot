#ifndef camera_h
#define camera_h

#include <iostream>

#include "GraphicIncludes.h"
#include "../Utils/Structures/Vector3.h"

class Camera
{
private:
	float alpha;
	float beta;

public:
	Vector3 eyeDest, eye, up;
	Vector3 uDest, vDest, nDest;
	Vector3 u, v, n;

	Camera()
	{
		alpha = 0.3;
		beta = 0.7071;
		eye = Vector3(0, 2.5, 1.5);
		up =  Vector3(0, 0, 1);
		u 	= Vector3(1, 0, 0);
		v 	= Vector3(0, -0.707, 0.707);
		n 	= Vector3(0, 0.707, 0.707);
		eyeDest = eye;
		uDest = u;
		vDest = v;
		nDest = n;
	}

	void updateEye()
	{
		static float speed = 0.05f;
		eye += (eyeDest - eye) * speed;
		n += (nDest - n) * speed;
		u += (uDest - u) * speed;
		v += (vDest - v) * speed;
		updateView();
	}

	void calcUV()
	{
		uDest = Vector3(up.cross(nDest));
		uDest.normalize();
		vDest = Vector3(nDest.cross(uDest));
		vDest.normalize();
	}

    void updateView()
    {
    }

    inline void setLookAt()
	{
		gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, up.x, up.y, up.z);
	}
};

#endif
