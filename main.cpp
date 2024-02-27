#include <iostream>

#include "recursive_back_tracker.h"

void display_callback()
{

	glClear(GL_COLOR_BUFFER_BIT);
	drawgrid();
	glutSwapBuffers();
	traverse();
	glutSwapBuffers();

}

void reshape_callback(int w, int h)
{
	int window_width = w;
	int window_height = h;

	glViewport(0, 0, (GLsizei) w, GLsizei(h));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, gridsize, 0.0, gridsize, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

}
void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutSwapBuffers();
}
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // NOLINT(hicpp-signed-bitwise)
	glutInitWindowSize(width, height);
	glutCreateWindow("Maze");
	glutReshapeFunc(reshape_callback);
	init();
	glutDisplayFunc(display_callback);
	glutMainLoop();

	return 0;

}