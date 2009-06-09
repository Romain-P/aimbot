/*
 * main.cpp
 *
 *  Created on: Jun 8, 2009
 *      Author: Corey
 */

#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL\glut.h>

void init(int,char**);

void idle();

void keyboard(unsigned char key, int x, int y);

float testoperator = 5;

 int main(int c, char** argv)
 {

	 init(c, argv);
	 return 0;
 }

 void display();

 void init(int n, char** argv)
 {

	 glutInit(&n, argv);
	 glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	 glutCreateWindow(argv[0]);
	 glutFullScreen();
	 glutDisplayFunc(display);
	 glutIdleFunc(idle);
	 glutKeyboardFunc(keyboard);
	 glutMainLoop();
 }

 void idle()
 {
	 testoperator++;
	 if (testoperator > 5)
	 {
		 testoperator = 0;
	 }
	 glutPostRedisplay();
 }

 void display()
 {
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glClearColor(0.5, 0.5, 0.5, 0.0);
	 glColor3f(0.8f,0.3f,0.6f);
	 glBegin(GL_QUADS);
	 glVertex2f(testoperator,testoperator);
	 glVertex2f(testoperator,testoperator*20);
	 glVertex2f(testoperator*20,testoperator*20);
	 glVertex2f(testoperator*20,testoperator);
	 glEnd();
	 glutSwapBuffers();
 }

 void keyboard(unsigned char key, int x, int y)
 {
	 if(key == 27) exit(0);
 }
