#include "Curves.h"
using namespace std;

void initLight()
{
	glEnable(GL_LIGHTING);

	float light0_Position[] = { 0, 0, -1, 1.0 };
	float light0_ambient[] = { 0.5, 0.5, 0.7, 1.0 };
	float light0_diffuse[] = { 0.8, 1.0, 0.5, 1.0 };
	float light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	float light1_position[] = { 0, 0, 1, 1.0 };
	float light1_diffuse[] = { 0.8, 0.2, 0.2, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light0_Position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

void init(int n, char** argv)
{
	glutInit(&n, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutFullScreen();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glLineWidth(1.0);
	glPointSize(2.0);
	glDepthFunc(GL_LESS);
	glDepthMask(GL_FALSE);
	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5, 0.5, 0.5, 0.0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void motion(int x, int y)
{
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
}

void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(5, glutGet(GLUT_SCREEN_WIDTH) / (float) glutGet(GLUT_SCREEN_HEIGHT), 0.1, 1000);
	gluLookAt(0, 0, 0, 0, 1, 0, 0, 1, 0);
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
		exit(0);

	glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
	if(key == GLUT_KEY_LEFT)
		glTranslatef( 0.1,  0, 0);

	else if(key == GLUT_KEY_RIGHT)
		glTranslatef(-0.1,  0, 0);

	else if(key == GLUT_KEY_UP)
		glTranslatef( 0,  0.1, 0);

	else if(key == GLUT_KEY_DOWN)
		glTranslatef( 0, -0.1, 0);
	glutPostRedisplay();
}

void idle()
{
	glutPostRedisplay();
}

