#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

		Point& operator =(Point point);
	public:

		Point();
		~Point();
		Point(Point const &p);
		Point(float const x, float const y);
		
		Fixed const GetX() const;
		Fixed const GetY() const;

		
};

//a, b, c corners of triangle, Point is point in or not in dreieck
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif