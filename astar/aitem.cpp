#include "aitem.h"

using namespace std;

AItem::AItem(){
 	hx = 0;
	gx = 0;
	p = Point{0,0};
}
AItem::AItem(int h, int g, Point coord){
 	hx = h;
	gx = g;
	p = coord;
}
void AItem::calcH(Point target, string type){
	if(type == "manhattan"){
		hx = abs(p.x-target.x) + abs(p.y-target.y);
	}
	if(type == "euclidean"){
		hx = sqrt(pow(abs(p.x-target.x),2)+pow(abs(p.y-target.y),2));
	}
}
//Unified function to make the main loop a little easier to read!
//I try to handle all of the h(x)/g(x) calculations and queue/grid adjustments inside of these functions.
	
void AItem::getAdj(Maze &m){
	getN(m);
	getS(m);
	getE(m);
	getW(m);
}
void AItem::getN(Maze &m){
	Point loc = Point(p.x,p.y-1);
	AItem candidate = AItem(0,gx+1,loc);

	if(candidate.p.y >= 0 and candidate.p.y < m.height and m.grid[candidate.p.y][candidate.p.x] != '#' and m.path.count(candidate.p) == 0){
		candidate.calcH(m.finish, m.heuristic);
		m.path[candidate.p] = this->p;
		m.agenda.push(candidate);
	}
}
void AItem::getS(Maze &m){
	Point loc = Point(p.x,p.y+1);
	AItem candidate = AItem(0,gx+1,loc);

	if(candidate.p.y >= 0 and candidate.p.y < m.height and m.grid[candidate.p.y][candidate.p.x] != '#' and m.path.count(candidate.p) == 0){
		candidate.calcH(m.finish, m.heuristic);
		m.path[candidate.p] = this->p;
		m.agenda.push(candidate);
	}
}
void AItem::getE(Maze &m){
	Point loc = Point(p.x+1,p.y);
	AItem candidate = AItem(0,gx+1,loc);

	if(candidate.p.x >= 0 and candidate.p.x < m.width and m.grid[candidate.p.y][candidate.p.x] != '#' and m.path.count(candidate.p) == 0){
		candidate.calcH(m.finish, m.heuristic);
		m.path[candidate.p] = this->p;
		m.agenda.push(candidate);
	}
}
void AItem::getW(Maze &m){
	Point loc = Point(p.x-1,p.y);
	AItem candidate = AItem(0,gx+1,loc);

	if(candidate.p.x >= 0 and candidate.p.x < m.width and m.grid[candidate.p.y][candidate.p.x] != '#' and m.path.count(candidate.p) == 0){
		candidate.calcH(m.finish,m.heuristic);
		m.path[candidate.p] = this->p;
		m.agenda.push(candidate);
	}
}
bool AItem::operator >(const AItem &a) const{ 
    return hx + gx < a.hx + a.gx;
}
bool AItem::operator <(const AItem &a) const{ //https://www.techiedelight.com/use-custom-objects-keys-std-map-cpp/
    return (hx + gx > a.hx + a.gx);
}
bool AItem::operator ==(const AItem &a) const{
    return (hx+gx == a.hx + a.gx);
}

