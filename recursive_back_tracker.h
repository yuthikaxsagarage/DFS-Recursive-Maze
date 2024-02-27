//
// Created by yuthika on 2019-10-04.
//

#ifndef MAZE_RECURSIVE_BACK_TRACKER_H
#define MAZE_RECURSIVE_BACK_TRACKER_H

#include "utils.h"

void erase_wall(point, int);
t_point starting_position();
int random_gen(int a, int b);
bool check_set(t_point P);

void traverse();



#endif //MAZE_RECURSIVE_BACK_TRACKER_H
