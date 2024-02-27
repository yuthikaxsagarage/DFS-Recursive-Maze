//
// Created by yuthika on 2019-10-04.
//
#include <iostream>
#include <random>
#include "recursive_back_tracker.h"
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;
int counter = 0;

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

ostream& operator<<(ostream& stream, const t_point& item)
{
	stream << item.x << " - " << item.y;
	return stream;
}

struct SimpleHash {
  size_t operator()(const t_point& p) const
  {
	  return p.x ^ p.y;
  }
};

unordered_set<t_point, SimpleHash> grid_set;

stack<t_point> rb_stack;

int random_gen(int a, int b)
{

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(a, b);

	return dist6(rng);
}

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g)
{
	std::uniform_int_distribution<> dis(0, std::distance(start, end)-1);
	std::advance(start, dis(g));
	return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return select_randomly(start, end, gen);
}

t_point starting_position()
{
	int init_x = random_gen(1, 17);
	int init_y = random_gen(1, 17);

	t_point start_cell = {init_x, init_y};

	return start_cell;
}


bool* check_free_neighbors(t_point cell, bool* p)
{

	t_point right = {cell.x+1, cell.y};
	t_point left = {cell.x-1, cell.y};
	t_point top = {cell.x, cell.y+1};
	t_point bottom = {cell.x, cell.y-1};

	auto got1 = grid_set.find(right);
	auto got2 = grid_set.find(left);
	auto got3 = grid_set.find(top);
	auto got4 = grid_set.find(bottom);

	if (got1==grid_set.end()) {
		p[0] = true;
	}
	if (got2==grid_set.end()) {
		p[1] = true;
	}
	if (got3==grid_set.end()) {
		p[2] = true;
	}
	if (got4==grid_set.end()) {
		p[3] = true;
	}
	return p;

}

t_point current_cell = starting_position();

bool nontrav()
{
	t_point c{};
	for (int i = 0; i<gridsize-1; i++) {

		c.x = i;
		c.y = 0;
		grid_set.insert(c);
	}
	for (int i = 0; i<gridsize-1; i++) {

		c.x = 0;
		c.y = i;
		grid_set.insert(c);
	}
	for (int i = 0; i<gridsize-1; i++) {

		c.x = i;
		c.y = 19;
		grid_set.insert(c);
	}
	for (int i = 0; i<gridsize-1; i++) {

		c.x = 19;
		c.y = i;
		grid_set.insert(c);
	}
	return true;

}

void traverse()
{
	if (!nontrav()) {
		nontrav();
	}

	vector<int> direction_vec;
	direction_vec.clear();
	bool* array;

	bool direct_array[4] = {false, false, false, false};
	counter++;

	int& vx = current_cell.x;
	int& vy = current_cell.y;
	grid_set.insert(current_cell);

	cout << current_cell << endl;
	t_point next_cell = {};

	point e = {static_cast<GLfloat>(vx), static_cast<GLfloat>(vy), 1.0, 1.0, 1.0};
	point e_right = {e.x+1, e.y, 1.0, 1.0, 1.0};
	point etop = {e.x, e.y+1, 1.0, 1.0, 1.0};
	point e_diag = {e.x+1, e.y+1, 1.0, 1.0, 1.0};

	array = check_free_neighbors(current_cell, direct_array);

	for (int i = 0; i<static_cast<int>(sizeof(array)/2*sizeof(*array)); i++) {
		if (array[i]) {
			direction_vec.push_back(i);
		}
	}
	if (!direction_vec.empty()) {
		int direction = *select_randomly(direction_vec.begin(), direction_vec.end())+1;

		//starting cell is done, now choose a direction to go, to do that we need to check neighbors if they in the set then generate a random number accordingly

		cout << "this is direction --" << direction << endl;

		if (direction==1 && vx>=1 && vx<=gridsize-3 && vy>=1
				&& vy<=gridsize-2) { //cannot destroy outer walls // 1 means right
			vx++;

			rb_stack.push(current_cell);
			cout << "came here to x++ " << current_cell << endl;
			drawline(e_right, e_diag);

		}
		else if (direction==2 && vx>1 && vx<=gridsize-2 && vy>=1 && vy<=gridsize-2) { //2 means left

			vx--;

			rb_stack.push(current_cell);
			cout << "came here to x-- " << current_cell << endl;
			drawline(e, etop);

		}

		else if (direction==3 && vx>=1 && vx<=gridsize-2 && vy>=1 && vy<gridsize-2) { //3 means top

			vy++;

			rb_stack.push(current_cell);
			cout << "came here to y++ " << current_cell << endl;
			drawline(etop, e_diag);

		}
		else if (direction==4 && vx>=1 && vx<=gridsize-2 && vy>1 && vy<=gridsize-2) { //4 means down

			vy--;

			rb_stack.push(current_cell);
			cout << "came here to y-- " << current_cell << endl;
			drawline(e, e_right);

		}
	}
	else {
		rb_stack.pop();
		current_cell = rb_stack.top();

	}
	while (grid_set.size()<gridsize*gridsize-1) {
		if (rb_stack.empty()) {
			break;
		}
		glutSwapBuffers();
		traverse();
	}
}



