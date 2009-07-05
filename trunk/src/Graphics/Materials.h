#ifndef materials_h
#define materials_h

#include "Glut/GraphicIncludes.h"

namespace Materials
{
	static void glowing(float r, float g, float b)
	{
		float em[] = { r, g, b, 1.f };
		float col[] = { r, g, b, 0.6f };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, col);
		glMaterialfv(GL_FRONT, GL_EMISSION, em);
	}

	static void none()
	{
		float em[] = {0, 0, 0, 1.f};
		float col[] = { 0.5f, 0.5f, 0.5f, 1.f };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, col);
		glMaterialfv(GL_FRONT, GL_EMISSION, em);
	}
}

#endif
