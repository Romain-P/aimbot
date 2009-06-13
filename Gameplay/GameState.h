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

	enum inGameStates
	{
		//I guess these sort of depend upon the specific game
	};

	GameState();

	/*
	static void updateDelegate();
	void updateState();
	*/

	int getGameState()
	{
		return state;
	}

};

#endif