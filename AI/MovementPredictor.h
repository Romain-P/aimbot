#ifndef movementpredictor_h
#define movementpredictor_h

class MovementPredictor : public Predictor
{
private:
	vector<Position3> movementHistory;
public:

	MovementPredictor() : Predictor()
	{

	}

	void addMovement(Position& position)
	{
		movementHistory.push_back(position);
	}
};

#endif
