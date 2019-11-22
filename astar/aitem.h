#ifndef AITEM_H
#define AITEM_H

#include <cmath>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

#include "maze.h"
#include "point.h"

using namespace std;

struct Maze;

struct AItem{
	
	int hx;
	int gx;
	Point p;

	AItem();
	AItem(int h,int g,Point coord);

	void getAdj(Maze &m);
	void getN(Maze &m);
	void getS(Maze &m);
	void getE(Maze &m);
	void getW(Maze &m);

	void calcH(Point target, string type);

	bool operator >(const AItem &a) const;
	bool operator <(const AItem &a) const;
	bool operator ==(const AItem &a) const;
};
#endif
