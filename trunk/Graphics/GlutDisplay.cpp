#include "GlutDisplay.h"

GlutDisplay* glutDisplay;

GlutDisplay::GlutDisplay()
{
	glutDisplay = this;
}

inline void GlutDisplay::displayDelegate()
{
	glutDisplay->displayFunction();
}

inline ovid GlutDisplay::reshapeDelegate(int w, int h)
{
	glutDisplay->reshapeFunction(w, h);
}
