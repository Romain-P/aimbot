#ifndef currentplayer_h
#define currentplayer_h

#include "Player.h"
#include "../../Utils/Structures/Singleton.h"
#include "../../Graphics/Camera.h"

class CurrentPlayer : public Player, public Singleton<CurrentPlayer>
{
private:
	Camera* camera;

protected:
	friend class Singleton<CurrentPlayer>;
	CurrentPlayer()
	{
		camera = NULL;
	}

public:
	void setCamera(Camera* cam)
	{
		camera = cam;
	}

};

#endif
