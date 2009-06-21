#include "Camera.h"
#include "GlutDisplay.h"

Camera::Camera()
{
	eye = Vector3(0, 3, 0);
	up  = Vector3(0, 1, 0);
	n 	= Vector3(0, 2, 0);
	nDest = n;
	calcUV();
	eyeDest = eye;
}

void Camera::setDisplay(GlutDisplay* display)
{
	this->display = display;
}

void Camera::updateView()
{
	static float speed = 0.05f;
	eye += (eyeDest - eye) * speed;
	n += (nDest - n) * speed;
	gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, up.x, up.y, up.z);
}

void Camera::calcUV()
{
	uDest = Vector3(up.cross(nDest));
	uDest.normalize();
	vDest = Vector3(nDest.cross(uDest));
	vDest.normalize();
}

void Camera::setLookAt()
{
	gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, up.x, up.y, up.z);
}
