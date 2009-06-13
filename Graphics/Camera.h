#ifndef camera_h
#define camera_h

#include "GraphicIncludes.h"
#include <iostream>
#include "../Utils/Vector3.h"

class Camera
{
private:
	double viewAngle, aspect, nearDist, farDist;
	float alpha;
	float beta;
	float z;

public:
	Vector3 eyeDest;
	Vector3 eye;
	Vector3 up;
	Vector3 uDest, vDest, nDest;
	Vector3 u, v, n;

	Camera()
	{
		alpha = 0.3;
		beta = 0.7071;
		z = 2;
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

	void setShape(float vAng, float asp, float nearD, float farD)
	{
		viewAngle = vAng;
		aspect = asp;
		nearDist = nearD;
		farDist = farD;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(viewAngle, aspect, nearDist, farDist);
		gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, 0, 0, 1);
	}

	void updateEye()
	{
		float speed = 0.05f;
		eye += (eyeDest - eye) * speed;
		n += (nDest - n) * speed;
		u += (uDest - u) * speed;
		v += (vDest - v) * speed;
		updateView();
	}

	void circle(float hAngle, float vAngle, Vector3 centre)
	{
		alpha += hAngle;
		beta += vAngle;

		constrain(beta, 0.05f, 1.5f);

		nDest = Vector3(sin(alpha), cos(alpha), tan(beta));
		nDest.normalize();
		calcUV();
		eyeDest = nDest * z + centre;

		updateView();
	}

	void calcUV()
	{
		uDest = Vector3(up.cross(nDest));
		uDest.normalize();
		vDest = Vector3(nDest.cross(uDest));
		vDest.normalize();
	}

	void zoom(float zoom, Vector3 centre)
	{
		z *= zoom;
		eyeDest = nDest * z + centre;
		updateEye();
	}

    void updateView()
    {
    	setProjectionMatrix();
    }

	void setProjectionMatrix(void)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(viewAngle, aspect, nearDist, farDist);
		gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, up.x, up.y, up.z);
	}

};

#endif
