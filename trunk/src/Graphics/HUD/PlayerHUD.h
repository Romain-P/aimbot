#ifndef playerhud_h
#define playerhud_h

#include <string>
#include <sstream>

#include "Crosshairs/Crosshair.h"
#include "Crosshairs/Cross.h"
#include "../Drawable.h"
#include "../TextRenderer.h"
#include "../Colour.h"
#include "../../Game/GameState.h"

class Updater;
class GameCoordinator;

using std::string;
using std::stringstream;

class PlayerHUD : public Drawable, public TextRenderer
{
private:
	bool showFPS;
	bool showPosition;
	bool showAngles;

	GameState* state;
	Updater* updater;
	Crosshair* crosshair;
	GameCoordinator* coordinator;

public:
	PlayerHUD(GameState* gameState, Updater* gameUpdater, GameCoordinator* coordinator);
	virtual ~PlayerHUD();
	void drawText(string& text, float leftX, float topY);
	void draw();
	void drawFPS();
	void drawPosition();
	void drawAngles();
	void drawFooterBar();
	void toggleFPS();
	void togglePosition();
	void toggleAngles();
};


#endif
