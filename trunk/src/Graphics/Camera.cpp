#include "Camera.h"
#include "Glut/GlutDisplay.h"

Camera::Camera()
{
	theta = 0;
	phi = 0;
	start = Position3(0, 0, 0);
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

	if(phi < -1.57f) phi = -1.57f;
	if(phi > 1.57f) phi = 1.57f;

	cphi = cosf(phi);
	ctheta = cosf(theta);
	sphi = sinf(phi);
	stheta = sinf(theta);

	look.x = stheta * cphi;
	look.y = sphi;
	look.z = -ctheta * cphi;
}

// TODO: rethink where the camera's position is controlled, involving the player object
void Camera::updateVelocity(const Vector3& direction)
{
	velocity.x = 3 * (ctheta * direction.x - stheta * direction.z);
	velocity.z = 3 * (stheta * direction.x + ctheta * direction.z);
}
