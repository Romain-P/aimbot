#ifndef devconsole_h
#define devconsole_h

#include <string>
#include <sstream>
#include <list>

#include "PlayerHUD.h"
#include "../Drawable.h"
#include "../TextRenderer.h"
#include "../Colour.h"
#include "../../Utils/Misc/Tokenizer.h"
#include "../../Utils/Misc/StringUtils.h"

using std::string;
using std::stringstream;
using std::list;

class GlutDisplay;

class Message
{
public:
	string text;
	Colour colour;

	Message(const string& t, const Colour& c) :
		text(t),
		colour(c)
	{
	}
};

class DevConsole : public Drawable, public TextRenderer
{
private:
	bool visible;
	float size;
	unsigned int messagesShown;
	unsigned int maxMessages;
	string currentText;

	stringstream ss;

	list<Message> messages;
	PlayerHUD* playerHud;
	GlutDisplay* glutDisplay;

public:
	enum position { TOP, LEFT, BOTTOM, RIGHT };

	DevConsole(PlayerHUD* hud, GlutDisplay* display);
	~DevConsole();

	void pushMessage(Message message);
	void executeCommand(string& command);
	void toggleVisibility();
	void putChar(unsigned char ch);
	void eraseWord();
	bool isVisible();
	void draw();

};


#endif
