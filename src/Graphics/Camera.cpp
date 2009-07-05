#include "Camera.h"
#include "Glut/GlutDisplay.h"

Camera::Camera()
{
	theta = 3.14;
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
	static float c;
	theta += dx;
	phi += dy;

	c = cosf(phi);
	look.x = sinf(theta) * c;
	look.y = sinf(phi);
	look.z = -cosf(theta) * c;
}

void Camera::updateVelocity(const Vector3& direction)
{
	velocity.x = 2 * (cos(theta) * direction.x - sin(theta) * direction.z);
	velocity.z = 2 * (sin(theta) * direction.x + cos(theta) * direction.z);
}
