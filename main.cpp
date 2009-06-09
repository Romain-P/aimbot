
#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>

int side = 100;

void init(int, char**);
void display();
void keyboard(unsigned char key, int x, int y);
void idle();

int main(int c, char**argv)
{
	init(c, argv);

	return 0;
}

void init(int c, char**argv)
{
	glutInit(&c, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutFullScreen();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);


	glColor3f(0.8f, 0.3f, 0.6f);
	glBegin(GL_QUADS);

	glVertex2f(0, 0);
	glVertex2f(0, side);
	glVertex2f(side, side);
	glVertex2f(side, 0);

	glEnd();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void idle()
{
	side++;

	if(side > 200) side = 100;

	glutPostRedisplay();
}
