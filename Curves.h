#ifndef section_h
#define section_h

#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <math.h>

void init(int c, char** argv);
void initLight();
void display();
void motion(int x, int y);
void mouse(int button, int state, int x, int y);
void idle();
void reshape(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);

void drawEnvironment();


#endif
