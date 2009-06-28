#include "Camera.h"
#include "GlutDisplay.h"

Camera::Camera()
{
	theta = 135;
	phi = 0;
	start = Position3(0, 0, 1);
	up  = Vector3(0, 1, 0);
	calcLook(0, 0);
}

void Camera::setDisplay(GlutDisplay* display)
{
	this->display = display;
}

void Camera::updateView()
{
	Position3 eye = this->getPosition();
	gluLookAt(eye.x, eye.y, eye.z,
			eye.x - look.x, eye.y - look.y, eye.z - look.z,
			up.x, up.y, up.z);
}

void Camera::calcLook(float dx, float dy)
{
	theta += dx;
	phi += dy;

	look.x = sin(theta) * cos(phi);
	look.y = sin(phi);
	look.z = -cos(theta) * cos(phi);
}

void Camera::updateVelocity(const Vector3& direction)
{
	velocity.x = 2 * (cos(theta) * direction.x - sin(theta) * direction.z);
	velocity.z = 2 * (sin(theta) * direction.x + cos(theta) * direction.z);
}
