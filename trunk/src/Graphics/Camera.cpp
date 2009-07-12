#include "Camera.h"
#include "Glut/GlutDisplay.h"

Camera::Camera()
{
	up  = Vector3(0, 1, 0);
}

void Camera::setDisplay(GlutDisplay* display)
{
	this->display = display;
}

void Camera::updateView()
{
	gluLookAt(eye.x, eye.y, eye.z,
			  eye.x - look.x, eye.y - look.y, eye.z - look.z,
			  up.x, up.y, up.z);
}

void Camera::setLook(Vector3 direction)
{
	look = direction;
}

void Camera::setEye(const Position3& position)
{
	eye = position;
}
