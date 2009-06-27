#ifndef devconsole_h
#define devconsole_h

#include <string>
#include <queue>

#include "PlayerHUD.h"
#include "../Orthographic.h"
#include "../../Utils/Misc/Tokenizer.h"

using std::string;
using std::queue;

class DevConsole : public Orthographic
{
private:
	bool visible;
	float size;
	unsigned int numMessages;
	queue<string> messages;
	PlayerHUD* playerHud;

public:
	enum position { TOP, LEFT, BOTTOM, RIGHT };

	DevConsole(PlayerHUD* hud) : Orthographic(500), playerHud(hud)
	{
	}

	virtual ~DevConsole()
	{

	}

	void pushMessage(const string& message)
	{
		messages.push(message);

		if(messages.size() > numMessages)
		{
			messages.pop();
		}
	}

	void executeCommand(const string& command)
	{
		Tokenizer tokenizer(command);
		string action = tokenizer.nextToken();
		string onWhat = tokenizer.nextToken();

		// sadly, have to declare martial law on regular brace-line formatting here
		// and we can't switch on strings. sonomabitch.
		/*
		switch(action) {
			case "stat": {
				switch(onWhat) {
				case "fps":
					playerHud->showFPS(true);
					break;
				}
				break;
			}
			case "set": {
				switch(onWhat) {
				case "fov":
					glutDisplay->setFOV(tokenizer.nextToken());
					glutDisplay->reshapeFunction(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_WIDTH));
					break;
				case "gamma":

					break;
				}
				break;
			}
			case "enable": {
				switch(onWhat) {

				}
				break;
			}
			case "add": {

				break;
			}
		}
		*/

	}

	void toggleVisibility()
	{
		visible = !visible;
	}

	bool isVisible()
	{
		return visible;
	}

	void draw()
	{
		//
	}
};


#endif