#ifndef devconsole_h
#define devconsole_h

#include <string>
#include <queue>
#include "PlayerHUD.h"
#include "../../Utils/Tokenizer.h"

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
		Tokenizer tokenizer(command);
		string action = tokenizer.nextToken();
		string onWhat = tokenizer.nextToken();

		// have to declare martial law on regular brace-line formatting here
		switch(action) {
			case "stat": {
				switch(onWhat) {
				case "fps":
					playerHud->showFPS();
				}
				break;
			}
			case "set": {
				switch(onWhat) {
				case "fps":

				}
				break;
			}
			case "enable": {
				switch(onWhat) {
				case "fps":

				}
				break;
			}
		}

	}

	void setActive()
	{

	}
};


#endif
