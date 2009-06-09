#include "Curves.h"


int main(int c, char**argv)
{
	init(c, argv);

	return 0;
}


/*

	for(int i = 0; i < xRes / 2; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 - 0.333333,
				table[i][currentCurve].y + table[i][currentCurve].x - 1);
	}
	for(int i = xRes / 2; i < xRes; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 - 0.333333,
				 table[i][currentCurve].y - table[i][currentCurve].x - 1);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i < xRes / 2; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 + 0.333333,
				1-table[i][currentCurve].y - table[i][currentCurve].x);
	}
	for(int i = xRes / 2; i < xRes; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 + 0.333333,
				1 + table[i][currentCurve].x - table[i][currentCurve].y);
	}
	glEnd();


	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	for(int i = 0; i < xRes / 2; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 - 0.333333,
				table[i][currentCurve].y + table[i][currentCurve].x - 1);
	}
	for(int i = xRes / 2; i < xRes; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 - 0.333333,
				 table[i][currentCurve].y - table[i][currentCurve].x - 1);
	}
	for(int i = 0; i < xRes / 2; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 + 0.333333,
				1-table[i][currentCurve].y - table[i][currentCurve].x);
	}
	for(int i = xRes / 2; i < xRes; i++) {
		glVertex2f(table[i][currentCurve].x * 0.666666 + 0.333333,
				1 + table[i][currentCurve].x - table[i][currentCurve].y);
	}


 */
