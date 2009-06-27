#ifndef playerhud_h
#define playerhud_h

#include <string>
#include <sstream>

#include "../Drawable.h"
#include "../TextRenderer.h"
#include "../../Game/GameState.h"

class Updater;

using std::string;
using std::stringstream;

class PlayerHUD : public Drawable, public TextRenderer
{
private:
	bool showFPS;

	GameState* state;
	Updater* updater;

public:
	PlayerHUD(GameState* gameState, Updater* gameUpdater);
	virtual ~PlayerHUD() {}
	void drawText(string& text, float leftX, float topY);
	void draw();
	void drawFPS();
	void toggleFPS();
};


#endif
