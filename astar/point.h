#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include <unordered_map>

using namespace std;

struct Point{
	int x;
	int y;

	Point();
	Point(int a,int b);

	void print();
	bool operator ==(const Point &a) const;
	bool operator !=(const Point &a) const;

};

namespace std	//Standard namespace override example from class.
{
	template<> struct hash<Point>
	{
		std::size_t operator()(Point const& p) const noexcept
		{
			return (p.x << 4 * p.x) + p.y; //Hashed value...
		}
	};
}

#endif
