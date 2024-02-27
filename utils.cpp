//
// Created by yuthika on 2019-10-04.
//
#include "utils.h"
GLfloat p = 0, q = 0;

void drawgrid()
{
	point V3 = {p, q+1, 0.0, 0.0, 0.0};

	for (GLfloat i = 1; i<=gridsize-2; i++) {
		for (GLfloat j = 1; j<=gridsize-1; j++) {
			point V1 = {i, j, 0.0, 0.0, 0.0};
			point V2 = {i+1, j, 0.0, 0.0, 0.0};
			drawline(V1, V2);
		}
	}
	for (GLfloat i = 1; i<=gridsize-1; i++) {
		for (GLfloat j = 1; j<=gridsize-2; j++) {
			point V1 = {i, j, 0.0, 0.0, 0.0};
			point V2 = {i, j+1, 0.0, 0.0, 0.0};
			drawline(V1, V2);
		}
	}

}

void drawline(point X, point Y)
{
	line l = {X, Y};
	l.A = X;
	l.B = Y;
	glColor3f(l.A.red, l.A.green, l.A.green);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2f(l.A.x, l.A.y);
	glVertex2f(l.B.x, l.B.y);
	glEnd();
}
void drawpoint(GLfloat X, GLfloat Y)
{
	point v = {X, Y, 0.0, 0.0, 0.0};
	glBegin(GL_POINT);
	glColor3f(v.red, v.green, v.blue);
	glVertex2f(v.x, v.y);
	glEnd();
}
