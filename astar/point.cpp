#include "point.h"

using namespace std;

Point::Point(int a, int b){
	x = a;
	y = b;
}
Point::Point(){		//Sets default values to something outside the Cartesian plane.
	x = -1;			//I will use (-1,-1) as the standard for showing that no changes have occurred, or that
	y = -1;			//a point has now become out of bounds due to operations like checking adjacent grid points.
}
void Point::print(){	//God bless printf.
	printf("%i,%i\n",x,y);
}	
bool Point::operator ==(const Point &a) const{
	return (x == a.x and y == a.y);
}
bool Point::operator !=(const Point &a) const{
	return (x != a.x or y != a.y);
}

