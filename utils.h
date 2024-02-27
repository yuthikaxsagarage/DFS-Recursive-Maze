//
// Created by yuthika on 2019-10-04.
//

#ifndef UTILS_H
#define UTILS_H
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

#define width 700
#define height 700
#define  gridsize 20
using namespace std;

struct point {
  GLfloat x;
  GLfloat y;
  GLfloat red;
  GLfloat blue;
  GLfloat green;

};

struct line {
  point A;
  point B;
};

struct t_point { // t_point is used for traversing and point is used only for drawing stuff in the glut grid

  int x;
  int y;

  bool operator==(const t_point& rhs) const
  {
	  return ((this->x==rhs.x) && (this->y==rhs.y));
  }

  bool operator<(const t_point& rhs) const
  {
	  return this->x<rhs.x && this->y<rhs.y;
  }

};

void drawpoint(GLfloat, GLfloat);
void drawline(point, point);
void drawgrid();

#endif //UTILS_H
