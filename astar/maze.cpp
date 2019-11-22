#include "maze.h"

using namespace std;

Maze::Maze(string type){
	none = Point{-1,-1};	
	heuristic = type;
	start = new AItem(0,0,none);
}
Maze::Maze(){
	start = new AItem();
}
void Maze::replaceChar(int x, int y, char c){
	if(x < 0 or y < 0)
		return;
	grid[y][x] = c;
}
void Maze::loadGrid(string name){
	file.open(name);

	getline(file,line); //Gets the first dimensions for the grid, checks for additional puzzles later...
	stringstream input(line);
	input >> width;
	input >> height;

	for(int i = 0; i < height; ++i){
		getline(file,line);
		grid.push_back(line);
		for(int j = 0; j < width; ++j){
			if(line[j] == 'o'){
				start = new AItem(0,0,Point(j,i));
				start->calcH(finish,heuristic);
				path[start->p] = none;
			}
			if(line[j] == '*'){
				finish = Point{j,i};
			}
		}
	}
}
void Maze::printGrid(){
	cout << width << " " << height << endl;
	for(auto v : grid){
		cout << v << endl;
	}
	cout << "\nAssuming the origin of our coordinate plane is at the top left:" << endl;
	cout << "The Start \"o\" is at: (" << start->p.x << "," << start->p.y << ")\n";
	cout << "The Finish \"*\" is at: (" << finish.x << "," << finish.y << ")\n";

	if(start->hx == 1){
		cout << "Path of Length 1" << endl;
	}
}
void Maze::findPath(){
	agenda.push(*start); //Manually add starting item to the agenda.
	while(!agenda.empty()){
		AItem current = agenda.top();
		agenda.pop();
		current.getAdj(*this);   //"Explores" the node by finding its valid neighbors and adds them to the map and queue.
		if(current.p != start->p and current.p != finish){
			replaceChar(current.p.x,current.p.y,'-');
		}
		else{
			if(current.p == finish)
				break;
		}
		/*
		 *Explore current node by checking if it's the finish, if not, then
		 *1. Get neighbors via AItem::getAdj(), then
		 *2. Map their previous "Point" to the current
		 *3. Calculate their h(x)s
		 *4. Add to agenda for future processing ONLY IF the Point is in bounds AND if the map says that that Point has not been explored before.
		 */
	}
	if(path.count(finish)){     //Path was found...
		int i = 0;
		Point current = finish;
		while(current != none){
			current = path[current];
			if(current != start->p){
				replaceChar(current.x,current.y,'*');
				++i;
			}
		}
		cout << "Path of Length " << i << " was found!" << endl;
		printGrid();
	}
	else{
		cout << "No path found." << endl;
	}
}


