#ifndef playerhud_h
#define playerhud_h

#include <string>
#include <sstream>

#include "../Drawable.h"
#include "../../Game/GameState.h"

class Updater;

using std::string;
using std::stringstream;

class PlayerHUD : public Drawable
{
private:

	bool showFPS;
	GameState* state;
	Updater* updater;

public:
	PlayerHUD(GameState* gameState, Updater* gameUpdater);
	virtual ~PlayerHUD() {}
	void setShowFPS(bool show);
	void drawFPS();
	void drawText(string& text, float leftX, float topY);
	void draw();
};


#endif
