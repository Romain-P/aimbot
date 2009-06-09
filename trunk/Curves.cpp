#include "Curves.h"
using namespace std;

enum keys { ESC = 27 };

const static int xRes = 64;
const static int tRes = 128;

int mouseStartX = 0;
int mouseStartY = 0;
int lastY = 0;
int currentCurve = tRes/2;
float currentCurvef = tRes / 2;

double pi = 3.1415926535;
double pi2 = pi * 0.5;
double ipi2 = 1.0 / pi2;




class Curve
{
public:
	int cIndex;
	float shear;
	crd a;
	crd b;
	crd c;

	Curve(crd x, crd y, crd z)
	{
		a = x;
		b = y;
		c = z;
		shear = 0;
		cIndex = tRes / 2;
	}
	Curve(crd x, crd y, crd z, int cIndex, float shear)
	{
		a = x;
		b = y;
		c = z;
		this->cIndex = cIndex;
		this->shear = shear;
	}
};

std::vector<crd> points;
std::vector<Curve> curves;

crd table[xRes][tRes];

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
	glLineWidth(2.0);
	glPointSize(2.0);

	glDepthFunc(GL_LESS);
	glDepthMask(GL_FALSE);

	calcTable2();

	crd a, b, c, d;
	a.x = -0.5f; a.y = 0.0f;
	b.x =  0.0f; b.y = 1.0f;
	c.x =  0.5f; c.y = 0.0f;
	d.x =  1.0f; d.y = 0.5f;

	points.push_back(a);
	points.push_back(b);
	points.push_back(c);
	points.push_back(d);

	Curve one(a, b, c, 0, 0);
	Curve two(b, c, d, tRes / 2, -0.5);

	curves.push_back(one);
	curves.push_back(two);

	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5, 0.5, 0.5, 0.0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glTranslatef(-0.2, 0.5, 0);
		drawCurve();
	glPopMatrix();
	glutSwapBuffers();
}

void drawCurve()
{
	//LINES

	glColor3f(0.50, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i < points.size(); i++)
		glVertex2f(points.at(i).x, points.at(i).y);
	glEnd();

	//CURVES
	glColor3f(1.0, 1.0, 1.0);

	float rot, height, m, dx, dyba, dyca, pole, span, shear, sinrot, cosrot, x, y, s, t;
	crd a, b, c, d, icept;
	for(int curve = 0; curve < curves.size(); curve++)
	{
		int ccurve = curves.at(curve).cIndex;
		a = curves.at(curve).a;
		b = curves.at(curve).b;
		c = curves.at(curve).c;

		rot = -atan2( (c.y-a.y) , (c.x-a.x) );

		dx = (c.x - a.x);
		dyba = (b.y - a.y);
		dyca = (c.y - a.y);
		span = sqrt(dx * dx + dyca * dyca);
		m = dyca/dx;

		icept.x = (m*m * a.x + b.y * m - a.y*m + b.x)/(1 + m*m);
		icept.y = m * (icept.x - a.x) + a.y;

		height = dist(b, icept);
		d.x = 0.5 * (a.x + c.x);
		d.y = 0.5 * (a.y + c.y);
		shear = -sqrt(dist2(b, d) - height*height); // curves.at(curve).shear;
		pole = b.y < (a.y + c.y) * 0.5 ? -1 : 1;

		glBegin(GL_LINE_STRIP);
		for(int i = 0; i < xRes; i++)
		{
			x = table[i][ccurve].x;
			y = table[i][ccurve].y;

			sinrot = sin(rot);
			cosrot = cos(rot);

			s = x * span;
			t = y * pole * height;
			x = s * cosrot + t * (sinrot + cosrot * shear);
			y = s * (-sinrot) + t * (cosrot - sinrot * shear);

			glVertex2f(x + a.x, y + a.y);
		}

		glEnd();
	}
}

inline float dist(const crd& a, const crd& b)
{
	return sqrtf(dist2(a, b));
}

inline float dist2(const crd& a, const crd& b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void drawPoints()
{
	glDisable(GL_DEPTH_TEST);
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POINTS);
	for(int i = 0; i < xRes; i++)
	{
		glVertex2f(table[i][currentCurve].x, table[i][currentCurve].y);
	}
	glEnd();
	glEnable(GL_DEPTH_TEST);
}

float yValue(int theta, int index)
{
	static double tan;
	static double root;
	static double x;
	static double ret;
	tan = ::tan(pi2 * double(theta) / tRes);
	root = (ipi2 + tan) / (1 + tan);
	x = 2 * double(index) / xRes;
	ret = (1 - pow(x - 1, 4)) * root;
	return ret;
}

void calcTable2()
{
	float tan, temp;
	for(int i = 0; i < tRes; i++)
	{
		tan = ::tan(double(i) * pi2 / tRes);
		for(int j = 0; j < xRes/2; j++)
		{
			table[j][i].y = yValue(i, j);
			temp = tan - table[j][i].y * tan + ipi2;
			table[j][i].x = 0.5 * ::acos(table[j][i].y / temp) * temp / (1 + tan * pi2) + 0.5;
		}

		for(int j = xRes / 2; j < xRes; j++)
		{
			table[j][i].x = 1 - table[xRes - j - 1][i].x;
			table[j][i].y = table[xRes - j - 1][i].y;
		}
	}
}

void calcTransition()
{

}

void drawSurface()
{
	float z, nz;
	for(int i = 0; i < xRes - 1; i++) {
		glBegin(GL_QUAD_STRIP);
		for(int j = 0; j < tRes - 1; j++) {
			z = float(j) / tRes;
			nz = float(j+1) / tRes;

			glColor3f(1-z, z*z, z);
			glVertex3f(table[i][j].x, 	  table[i][j].y, z);
			glVertex3f(table[i+1][j].x,   table[i+1][j].y, z);
			glVertex3f(table[i][j+1].x,   table[i][j+1].y, nz);
			glVertex3f(table[i+1][j+1].x, table[i+1][j+1].y, nz);
		}
		glEnd();
	}
}

void drawLine()
{
	glColor3f(0.5, 0.2, 0.2);
	glBegin(GL_LINE_STRIP);

	glVertex2f(-1, 1);
	glVertex2f(-0.33333, 0);
	glVertex2f(0.33333, 1);
	glVertex2f(1, 0);

	glEnd();
}

void drawAxes()
{

	/*
	glColor4f(1, 1, 1, 0.5);
	glBegin(GL_LINES);

	glVertex2f(-1, 0.5);
	glVertex2f(1, 0.5);

	glVertex2f(0, -1);
	glVertex2f(0, 2);
	glEnd();
	*/
}

void motion(int x, int y)
{
	currentCurvef -= (y - lastY) * 0.3f;

	if(currentCurvef > tRes - 2)
		currentCurvef = tRes - 2;
	if(currentCurvef < 0)
		currentCurvef = 0;

	currentCurve = int(currentCurvef);

	lastY = y;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	lastY = y;
}

void reshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(5, glutGet(GLUT_SCREEN_WIDTH) / (float) glutGet(GLUT_SCREEN_HEIGHT), 0.1, 1000);
	gluLookAt(0, 0, 15, 0, 1, 0, 0, 1, 0);
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == ESC)			exit(0);
	else if(key == '+')		glScalef(1.1, 1.1, 1.1);
	else if(key == '-')		glScalef(0.9, 0.9, 0.9);

	glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
	if(key == GLUT_KEY_LEFT)		glTranslatef( 0.1,  0, 0);
	else if(key == GLUT_KEY_RIGHT)	glTranslatef(-0.1,  0, 0);
	else if(key == GLUT_KEY_UP)		glTranslatef( 0,  0.1, 0);
	else if(key == GLUT_KEY_DOWN)	glTranslatef( 0, -0.1, 0);

	/*
	if(key == GLUT_KEY_LEFT)		glRotatef( 5, 0, 1, 0);
	else if(key == GLUT_KEY_RIGHT)	glRotatef(-5, 0, 1, 0);
	else if(key == GLUT_KEY_UP)		glRotatef( 5, 1, 0, 0);
	else if(key == GLUT_KEY_DOWN)	glRotatef(-5, 1, 0, 0);
	*/

	glutPostRedisplay();
}

void idle()
{

	static int inc = 1;
	currentCurve+=inc;
	if(currentCurve > tRes - 2) inc = -1;
	if(currentCurve < 1)	inc = 1;

	glutPostRedisplay();
}

