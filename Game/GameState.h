#ifndef gamestate_h
#define gamestate_h

class GameState
{
private:
	int state;

public:
	enum macroStates
	{
		NEW_GAME,
		CHANGING_SETTINGS,
		GAME_IN_SESSION,
		GAME_OVER
	};

	enum ingameStates
	{
		//I guess these sort of depend upon the specific game
	};

	GameState();

	int getGameState()
	{
		return state;
	}
};

#endif
