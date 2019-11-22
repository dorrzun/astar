#ifndef MAZE_H
#define MAZE_H

#include <cmath>

#include <iostream>
#include <fstream>
#include <sstream>

#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

#include "point.h"
#include "aitem.h"

using namespace std;

struct AItem;

struct Maze{
	ifstream file;
	vector<string> grid;	//Contains ASCII art map.
	unordered_map<Point,Point> path; //Maps a Point to a predecessor.
	priority_queue<AItem> agenda;

	string line;
	string heuristic;	//Can be "manhattan" or "euclidean".

	int height;		
	int width;
	AItem* start;
	Point finish;
	Point none;	//Dud value for the map to point start back to something.

	Maze();
	Maze(string type);
	void loadGrid(string name);	
	void printGrid();
	void findPath();
	void replaceChar(int x, int y, char c);

};
#endif

