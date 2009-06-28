#ifndef devconsole_h
#define devconsole_h

#include <string>
#include <sstream>
#include <list>

#include "PlayerHUD.h"
#include "../Drawable.h"
#include "../TextRenderer.h"
#include "../../Utils/Misc/Tokenizer.h"

using std::string;
using std::list;

class GlutDisplay;

class DevConsole : public Drawable, public TextRenderer
{
private:
	bool visible;
	float size;
	unsigned int messagesShown;
	unsigned int maxMessages;
	string currentMessage;

	stringstream ss;

	list<string> messages;
	PlayerHUD* playerHud;
	GlutDisplay* glutDisplay;

public:
	enum position { TOP, LEFT, BOTTOM, RIGHT };

	DevConsole(PlayerHUD* hud, GlutDisplay* display);
	~DevConsole();

	void pushMessage(const string& message);
	void executeCommand(const string& command);
	void toggleVisibility();
	void putChar(unsigned char ch);
	bool isVisible();
	void draw();
	void drawMessages();

};


#endif
