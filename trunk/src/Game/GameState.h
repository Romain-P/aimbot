#ifndef gamestate_h
#define gamestate_h

class GameState
{
private:
	int macroState;
	int ingameState;

public:
	enum macroStates
	{
		NEW_GAME,
		LOADING_MAP,
		CHANGING_SETTINGS,
		GAME_IN_SESSION,
	};

	enum ingameStates
	{
		COUNTDOWN,
		PLAYING,
		IN_DEV_CONSOLE,

		//I guess these sort of depend upon the specific game
	};

	GameState()
	{
	}

	int getMacroState()
	{
		return macroState;
	}

	int getIngameState()
	{
		return ingameState;
	}
};

#endif
