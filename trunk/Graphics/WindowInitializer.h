#ifndef windowinitializer_h
#define windowinitializer_h

#include "GraphicIncludes.h"
#include "GlutDisplay.h"
#include "../Game/GameCoordinator.h"

class WindowInitializer
{
private:

public:
	WindowInitializer(int n, char** argv)
	{
		initializeWindow(n, argv);

		GameCoordinator* coordinator = new GameCoordinator();
		coordinator->initialize();

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
};

#endif
