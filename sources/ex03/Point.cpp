# include "Point.hpp"

Point::Point()
{
}
Point::~Point()
{
}
Point::Point(Point const &p) : x(p.GetX()), y(p.GetY())
{
}
Point::Point(float const x, float const y) : x(x), y(y)
{
}

Fixed const Point::GetX() const
{
	return (x);
}
Fixed const Point::GetY() const
{
	return (y);
}
