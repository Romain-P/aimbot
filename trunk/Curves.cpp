#include "Curves.h"
using namespace std;

// camera position
Vector3 c(3, 0, 3);
Vector3 u;
Vector3 v;
Vector3 n(0, 1, 0);



void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5, 0.5, 0.5, 0.0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	drawEnvironment();

	glPopMatrix();
	glutSwapBuffers();
}

void drawEnvironment()
{
	//only a big cube for now
	glColor3f(0.8, 0.2, 0.7);

	Vector3 faces[] = {
			Vector3( 1,  1,  1),
			Vector3( 1, -1,  1),
			Vector3( 1, -1, -1),
			Vector3( 1,  1, -1),
			Vector3(-1,  1,  1),
			Vector3(-1, -1,  1),
			Vector3(-1, -1, -1),
			Vector3(-1,  1, -1)
	};

	int indices[6][4] = {
			{ 6, 1, 2, 3 },
			{ 3, 2, 6, 7 },
			{ 7, 4, 5, 6 },
			{ 4, 0, 1, 5 },
			{ 0, 3, 7, 4 },
			{ 1, 2, 6, 5 }
	};

	glBegin(GL_QUADS);
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			glColor3f(i / float(12) + j / float(8), i*j / float(24), (20 - 2*i * j)/float(24));
			glVertex3f(faces[indices[i][j]].x * 2,
					faces[indices[i][j]].y * 2,
					faces[indices[i][j]].z * 2);
		}
	}
	glEnd();
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
	gluPerspective(45, glutGet(GLUT_SCREEN_WIDTH) / (float) glutGet(GLUT_SCREEN_HEIGHT), 0.1, 10);
	gluLookAt(c.x, c.y, c.z, n.x - c.x, n.y - c.y, n.z - c.z, 0, 1, 0);
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
		exit(0);

	else if(key == 'w')
	{
		c.x += 1;
		n.x += 1;
	}

	else if(key == 's')
	{
		c.x -= 1;
		n.x -= 1;
	}
	else if(key == 'a')
		c.z += 1;
	else if(key == 'd')
		c.z -= 1;
	else if(key == ' ')
		c.y += 1;

	glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
	cout << "special key pressed " << endl;
	int modifiers = glutGetModifiers();
	if(modifiers == GLUT_ACTIVE_CTRL)
		c.y -= 1;

	glutPostRedisplay();
}

void idle()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, glutGet(GLUT_SCREEN_WIDTH)/float(glutGet(GLUT_SCREEN_HEIGHT)), 0.01, 1000);
	gluLookAt(c.x, c.y, c.z, n.x - c.x, n.y - c.y, n.z - c.y, 0, 1, 0);
	glutPostRedisplay();
}


