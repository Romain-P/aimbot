#ifndef section_h
#define section_h

#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <math.h>

class crd
{
public:
	//crd(float x, y) { this->x = x; this->y = y; }

	float x, y;
	void operator=(const crd& other)
	{
		this->x = other.x;
		this->y = other.y;
	}
};


void init(int c, char** argv);
void initLight();
void display();
void motion(int x, int y);
void mouse(int button, int state, int x, int y);
void idle();
void reshape(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void drawAxes();
void calcTable();
void calcTable2();
void calcCurves();
void drawCurve();
void drawSurface();
void drawPoints();
void drawLine();
float yValue(int theta, int index);
float dist(const crd& a, const crd& b);
float dist2(const crd& a, const crd& b);

#endif
