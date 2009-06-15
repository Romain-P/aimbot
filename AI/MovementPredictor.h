#ifndef movementpredictor_h
#define movementpredictor_h

#include <vector>
#include "../Entities/Player.h"

using std::vector;

class MovementPredictor : public Predictor
{
private:
	vector<Position3> movementHistory;
public:

	MovementPredictor(Player* player) : Predictor()
	{

	}

	void addMovement(Position& position)
	{
		movementHistory.push_back(position);
	}
};

#endif
