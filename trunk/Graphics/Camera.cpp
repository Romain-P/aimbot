#include "Camera.h"
#include "GlutDisplay.h"

Camera::Camera()
{
	start = Position3(0, 0, 3);
	up  = Vector3(0, 1, 0);
	look = Vector3(0, 1, 0);
}

void Camera::setDisplay(GlutDisplay* display)
{
	this->display = display;
}

void Camera::updateView()
{
	Position3 eye = this->getPosition();
	gluLookAt(eye.x, eye.y, eye.z, look.x, look.y, look.z, up.x, up.y, up.z);
}

void Camera::calcLook(float dx, float dy)
{
	theta += dx;
	phi += dy;

	look.x = sin(theta) * cos(phi);
	look.y = sin(phi);
	look.z = cos(theta) * cos(phi);
}
