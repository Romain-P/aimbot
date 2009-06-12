#include "GraphicIncludes.h"

void initLight()
{
	glEnable(GL_LIGHTING);

	float l0Position[] = { 0, 0, -1, 1.0 };
	float l0Ambient[] = { 0.5, 0.5, 0.7, 1.0 };
	float l0Diffuse[] = { 0.8, 1.0, 0.5, 1.0 };
	float l0Specular[] = { 1.0, 1.0, 1.0, 1.0 };

	float l1Position[] = { 0, 0, 1, 1.0 };
	float l1Diffuse[] = { 0.8, 0.2, 0.2, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, l0Position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l0Specular);

	glLightfv(GL_LIGHT1, GL_POSITION, l1Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l1Diffuse);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}
