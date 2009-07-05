#include "DevConsole.h"
#include "../Glut/GlutDisplay.h"

DevConsole::DevConsole(PlayerHUD* hud, GlutDisplay* display) :
	Drawable(500),
	messagesShown(10),
	maxMessages(100),
	playerHud(hud),
	glutDisplay(display)
{
}

void DevConsole::pushMessage(const string& message)
{
	messages.push_back(message);

	if(messages.size() > messagesShown)
		messages.pop_front();
}

void DevConsole::executeCommand(string& command)
{
	StringUtils::toLower(command);

	Tokenizer tokenizer(command);
	string a = tokenizer.nextToken();
	string b = tokenizer.nextToken();
	string c = tokenizer.nextToken();

	if (command == "fps")
			playerHud->toggleFPS();
	else if (a == "fov" && b.length() > 0) {
		float fov;
		fov = atof(b.c_str());
		if (fov < 10)
			fov = 10;
		glutDisplay->setFOV(fov);
		glutDisplay->reshapeFunction(width, height);
	}
	else if(command == "position")
		playerHud->togglePosition();
	else if(command == "angles")
		playerHud->toggleAngles();
	else if (command == "clear")
		messages.clear();
	else if (command == "now folks")
	{
		pushMessage("Some of you might already know... what this car is.");
		pushMessage("And some of you do not.");
	}
	else
		pushMessage("Huh?\n");
}

void DevConsole::draw()
{
	if (!visible)
		return;

	int h1 = 190;
	int h2 = h1 + 18;
	glBegin(GL_QUADS);
		glColor4f(0.13f, 0.15f, 0.17f, 0.6f);
		glVertex2f(0, 0);
		glVertex2f(0, h1);
		glVertex2f(width, h1);
		glVertex2f(width, 0);

		glColor4f(0.13f, 0.15f, 0.17f, 0.8f);
		glVertex2f(0, h1+2);
		glVertex2f(0, h2);
		glVertex2f(width, h2);
		glVertex2f(width, h1+2);
	glEnd();

	glBegin(GL_LINES);
		glColor4f(0.06f, 0.06f, 0.06f, 1.0f);
		glVertex2f(0, h1+1);
		glVertex2f(width, h1+1);

		glVertex2f(0, h2);
		glVertex2f(width, h2);
	glEnd();

	glColor3f(0.8f, 0.82f, 0.84f);
	drawString(currentMessage, 0.1f, 5, h2 - 4);

	int i = 1;
	list<string>::reverse_iterator it = messages.rbegin();

	while(it != messages.rend())
	{
		drawString(*it, 0.1f, 5, 190 - i * 18);
		++it;
		++i;
	}
}

void DevConsole::toggleVisibility()
{
	visible = !visible;
}

bool DevConsole::isVisible()
{
	return visible;
}

void DevConsole::putChar(unsigned char ch)
{
	if(ch == '\n' || ch == '\r')
	{
		pushMessage(currentMessage);
		executeCommand(currentMessage);
		currentMessage = "";
	}
	else if(ch == '\b')
	{
		if(currentMessage.length() > 0)
			currentMessage = currentMessage.substr(0, currentMessage.length() - 1);
	}
	else
	{
		currentMessage += ch;
	}
}
