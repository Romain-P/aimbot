#ifndef aiplayer_h
#define aiplayer_h

#include <vector>

#include "Player.h"
#include "../AI/MovementPredictor.h"

using std::vector;

class AIPlayer : public Player
{
private:
	vector<MovementPredictor*> predictors;
public:

	AIPlayer(vector<Player*>& opponents)
	{
		for(int i = 0; i < opponents.size(); i++)
		{
			predictors.push_back(new MovementPredictor(opponents.at(i)));
		}
	}
};

#endif
