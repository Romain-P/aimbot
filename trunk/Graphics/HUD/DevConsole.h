#ifndef devconsole_h
#define devconsole_h

#include <string>
#include <queue>

class DevConsole
{
private:
	float size;
	int numMessages;
	std::queue<std::string> messages;

public:
	enum position { TOP, LEFT, BOTTOM, RIGHT };

	DevConsole()
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
};


#endif
