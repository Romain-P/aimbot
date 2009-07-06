#ifndef glutlighting_h
#define glutlignting_h

#include "GraphicIncludes.h"

namespace GlutLighting
{
	void initLight()
	{
		float aPos[] = { -2.0, 3.0, -2.0, 1.0 };
		float aAmb[] = { 0.1, 0.1, 0.1, 1.0 };
		float aDif[] = { 0.5, 0.5, 0.4, 1.0 };

		float bPos[] = { 2.0, 3.0, 2.0, 1.0 };
		float bDif[] = { 0.6, 0.6, 0.6, 1.0 };
		float bAmb[] = { 0.1, 0.1, 0.1, 1.0 };

		glLightfv(GL_LIGHT0, GL_POSITION, 	aPos);
		glLightfv(GL_LIGHT0, GL_AMBIENT, 	aAmb);
		glLightfv(GL_LIGHT0, GL_DIFFUSE,	aDif);

		glLightfv(GL_LIGHT1, GL_POSITION, 	bPos);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, 	bDif);
		glLightfv(GL_LIGHT1, GL_AMBIENT, 	bAmb);

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
	}
}


#endif
