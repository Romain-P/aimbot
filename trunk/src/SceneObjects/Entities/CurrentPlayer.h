#ifndef currentplayer_h
#define currentplayer_h

#include "Player.h"
#include "../../Utils/Structures/Singleton.h"
#include "../../Graphics/Camera.h"

class CurrentPlayer : public Player, public Singleton<CurrentPlayer>
{
private:

	float cphi;
	float sphi;
	float ctheta;
	float stheta;

	Camera* camera;

	Position3 closest;

protected:
	friend class Singleton<CurrentPlayer>;
	CurrentPlayer() :
		theta(0),
		phi(0)
	{
		camera = NULL;
		start = Position3(0, 0, 0);
	}

public:
	float theta;
	float phi;

	void setCamera(Camera* cam)
	{
		camera = cam;
	}

	void updateVelocity(const Vector3& v)
	{
		velocity.x = speed * (ctheta * v.x - stheta * v.z);
		velocity.y = speed * (v.y);
		velocity.z = speed * (stheta * v.x + ctheta * v.z);
	}

	void calcLook(float dx, float dy)
	{
		theta += dx;
		phi += dy;

		if(phi < -1.5707f) phi = -1.5707f;
		if(phi > 1.5707f) phi = 1.5707f;

		cphi = cosf(phi);
		ctheta = cosf(theta);
		sphi = sinf(phi);
		stheta = sinf(theta);

		camera->setLook(Vector3(stheta * cphi, sphi, -ctheta * cphi));
	}


	void move(float timeStep)
	{
		if(timeStep <= 0) return;
		displacement += velocity * timeStep;
		camera->setEye(displacement);
	}
};

#endif
