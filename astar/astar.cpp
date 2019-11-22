#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char* argv[]){
	string filename = argv[1];
	if(argc == 2){	//No heuristic specified, so pick manhattan to calculate distance to finish.
		Maze curMaze = Maze("manhattan");
		curMaze.loadGrid(filename);
		curMaze.printGrid();
	}
	if(argc == 3){	//Manhattan/Euclidean
		Maze curMaze = Maze(argv[2]);
		curMaze.loadGrid(filename);
		curMaze.findPath();
	}
}
