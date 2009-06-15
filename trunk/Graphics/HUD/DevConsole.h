#ifndef devconsole_h
#define devconsole_h

#include <string>
#include <queue>
#include "PlayerHUD.h"


class DevConsole
{
private:
	float size;
	int numMessages;
	std::queue<std::string> messages;
	PlayerHUD* playerHud;

public:
	enum position { TOP, LEFT, BOTTOM, RIGHT };
	string* commands;

	DevConsole(PlayerHUD* hud) : playerHud(hud)
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
		string action = command.substring(0, command.firstOccurrenceOf
		switch(command)
		{
		case "stat fps":
			playerHud->showFPS();
			break;
		case "set fov"
		}
	}

	void setActive()
	{

	}
};


#endif
