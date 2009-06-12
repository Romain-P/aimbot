#ifndef windowinitializer_h
#define windowinitializer_h

#include "GraphicIncludes.h"
#include "GlutDisplay.h"
#include "../Input/InputHandler.h"

class WindowInitializer
{
public:
	WindowInitializer(int n, char** argv)
	{
		GlutDisplay* display = new GlutDisplay();

		initializeWindow(n, argv);
		setFunctionCallbacks();
		initGlutParameters();
		glutMainLoop();
	}

	void initializeWindow(int n, char** argv)
	{
		glutInit(&n, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
		glutCreateWindow(argv[0]);
		glutFullScreen();
	}

	void initGlutParameters()
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

	void setFunctionCallbacks()
	{
		glutDisplayFunc(&GlutDisplay::displayDelegate);
		glutReshapeFunc(&GlutDisplay::reshapeDelegate);
		glutMouseFunc(&InputHandler::mouseDelegate);
		glutMotionFunc(motion);
		glutIdleFunc(idle);
		glutKeyboardFunc(keyboard);
		glutSpecialFunc(specialKey);
	}
};

#endif
