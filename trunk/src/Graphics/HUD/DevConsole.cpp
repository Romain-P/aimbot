#include "DevConsole.h"
#include "../GlutDisplay.h"

DevConsole::DevConsole(PlayerHUD* hud, GlutDisplay* display) :
	Drawable(500),
	numMessages(10),
	playerHud(hud),
	glutDisplay(display)
{
}

void DevConsole::pushMessage(const string& message)
{
	messages.push_back(message);

	if(messages.size() > numMessages)
		messages.pop_front();
}

void DevConsole::executeCommand(const string& command)
{
	Tokenizer tokenizer(command);
	string a = tokenizer.nextToken();
	string b = tokenizer.nextToken();
	string c = tokenizer.nextToken();

	if(a == "stat")
	{
		if(b == "fps")
			playerHud->toggleFPS();
	}
	else if(a == "set")
	{
		if(b == "fov")
		{
			float fov;
			ss << c;
			ss >> fov;
			glutDisplay->setFOV(fov);
			glutDisplay->reshapeFunction(width, height);
		}
	}
}

void DevConsole::draw()
{
	if (!visible)
		return;

	glColor4f(0.13f, 0.15f, 0.17f, 0.6f);

	glBegin(GL_QUADS);
		glVertex2i(0, 0);
		glVertex2i(0, height / 4);
		glVertex2i(width, height / 4);
		glVertex2f(width, 0);
	glEnd();

	glColor3f(0.06f, 0.06f, 0.06f);
	glBegin(GL_LINES);
		glVertex2i(0, height / 4);
		glVertex2i(width, height / 4);
	glEnd();

	glColor3f(0.7f, 0.72f, 0.74f);
	drawString(currentMessage, 40, 200);

	int i = 0;
	list<string>::const_iterator it = messages.begin();

	while(it != messages.end())
	{
		drawString(*it, 40, i * 40);
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
	else
	{
		currentMessage += ch;
	}
}
