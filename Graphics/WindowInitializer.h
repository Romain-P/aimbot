#ifndef windowinitializer_h
#define windowinitializer_h

#include "GraphicIncludes.h"
#include "GlutDisplay.h"
#include "../Input/InputHandler.h"
#include "../Gameplay/GameState.h"

class WindowInitializer
{
private:
	GlutDisplay* display;
	GameState* gameState;
	InputHandler* inputHandler;

public:
	WindowInitializer(int n, char** argv)
	{
		display = new GlutDisplay();
		gameState = new GameState();
		inputHandler = new InputHandler();

		initializeWindow(n, argv);
		setFunctionCallbacks();
		initGraphicsOptions();

		glutMainLoop();
	}

	void initializeWindow(int n, char** argv)
	{
		glutInit(&n, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
		glutCreateWindow(argv[0]);
		glutFullScreen();
	}

	void setFunctionCallbacks()
	{
		glutDisplayFunc(&GlutDisplay::displayDelegate);
		glutReshapeFunc(&GlutDisplay::reshapeDelegate);

		glutMouseFunc(&InputHandler::mouseDelegate);
		glutMotionFunc(&InputHandler::motionDelegate);
		glutKeyboardFunc(&InputHandler::keyboardDelegate);
		glutKeyboardUpFunc(&InputHandler::keyUpDelegate);
		glutSpecialFunc(&InputHandler::specialKeyDelegate);

		glutIdleFunc(&Updater::updateDelegate);
	}

	void initGraphicsOptions()
	{
		glEnable(GL_POINT_SMOOTH);
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
		glLineWidth(1.0);
		glPointSize(2.0);
		glDepthMask(GL_FALSE);
		glEnable(GL_DEPTH_TEST);
	}
};

#endif
