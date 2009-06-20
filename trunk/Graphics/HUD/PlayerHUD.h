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
	stringstream ss;

public:
	PlayerHUD(GameState* gameState, Updater* gameUpdater);
	virtual ~PlayerHUD() {}
	void setShowFPS(bool show);
	void drawFPS();
	void drawText(string& text, int leftX, int topY);
	void draw();
};


#endif
