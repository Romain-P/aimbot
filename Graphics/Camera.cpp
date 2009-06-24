#include "Camera.h"
#include "GlutDisplay.h"

Camera::Camera()
{
	start = Position3(0, 0, 3);
	up  = Vector3(0, 1, 0);
	n 	= Vector3(0, 0, 2);
	nDest = n;
	calcUV();
}

void Camera::setDisplay(GlutDisplay* display)
{
	this->display = display;
}

void Camera::updateView()
{
	Position3 eye = this->getPosition();
	gluLookAt(eye.x, eye.y, eye.z, eye.x - n.x, eye.y - n.y, eye.z - n.z, up.x, up.y, up.z);
}

void Camera::calcUV()
{
	uDest = Vector3(up.cross(nDest));
	uDest.normalize();
	vDest = Vector3(nDest.cross(uDest));
	vDest.normalize();
}