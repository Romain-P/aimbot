#ifndef windowinitializer_h
#define windowinitializer_h

#include "GraphicIncludes.h"
#include "GlutDisplay.h"
#include "../Input/InputHandler.h"
#include "../Game/Updater.h"

class WindowInitializer
{
private:

public:
	WindowInitializer(int n, char** argv)
	{
		initializeWindow(n, argv);
		initGraphicsOptions();

		glutMainLoop();
	}

	~WindowInitializer()
	{
	}

	void initializeWindow(int n, char** argv)
	{
		glutInit(&n, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
		glutCreateWindow(argv[0]);
		glutFullScreen();
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
