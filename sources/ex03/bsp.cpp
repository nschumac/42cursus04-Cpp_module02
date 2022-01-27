#include "Point.hpp"

typedef struct	s_line
{
	float	m;
	float	t;
}				t_line;

typedef struct	s_plane
{
	t_line	vertex1;
	t_line	vertex2;
}				t_plane;

typedef struct	s_BspTree
{
	t_plane		p1;
	t_plane		p2;
	s_BspTree	*node1;
	s_BspTree	*node2;
}				t_BspTree;




float	ft_powf(float num, float powf)
{
	for (int c = 1; c < powf; ++c)
		num *= num;
	return (num);
}

float	ft_sqrtf(float num)
{
	float f;
	f = 1 - (1 - num) / 2;
	for (int i = 0; i < 30; ++i)
		f = f - ((ft_powf(f, 2.f)) - num) / (2 * f);
	return (f);
}

float	ft_dist(Point a, Point b)
{
	return (ft_sqrtf(ft_powf(b.GetX().toFloat() - a.GetX().toFloat(), 2.f) + ft_powf(b.GetY().toFloat() - a.GetY().toFloat(), 2.f)));
}
//Point on line: s + x * d = p -> solve for x if possible
// split into two formulas x and y coords

//Point in plane: a b c (ab x ac) = n -> n1x + n2x + d = 0
//calculate d by inserting point in plane :F

//FUCK BSP

// calculate distance subract from distance of other point and see if its in the fucking triangle
// FUKCING DO PLANES FLY
// IDKF

//FAKE BSP from what i undesrtand whatev
//RAytracing FOIk

bool	CorrectCross(Point	intersect, Point const org1, Point const org2, Point const point, Point outside)
{
	if (ft_dist(outside, point) <= ft_dist(intersect, outside))
		return (false);
	if (std::roundf(ft_dist(intersect, org1)) + std::roundf(ft_dist(intersect, org2)) != std::roundf(ft_dist(org1, org2)))
		return (false);
	return (true);
}

// DIFFERETN
// RAYTRACING BITCH
bool bsp( Point const a, Point const b, Point const c, Point const point)
{

	t_line l1;
	t_line l2;
	t_line l3;
	t_line ray;
	Point	outside(-c.GetX().toFloat() + 1000, -c.GetY().toFloat() + 500);

	int result;

	result = 0;

	ray.m = (point.GetY().toFloat() - (outside.GetY().toFloat())) / (point.GetX().toFloat() - (outside.GetX().toFloat()));
	ray.t = ray.m * -point.GetX().toFloat() + point.GetY().toFloat();

	// LINE ab
	l1.m =  (b.GetY().toFloat() - a.GetY().toFloat()) / (b.GetX().toFloat() - a.GetX().toFloat());
	l1.t = l1.m * -b.GetX().toFloat() + b.GetY().toFloat();

	// LINE ac
	l2.m = (c.GetY().toFloat() - a.GetY().toFloat()) / (c.GetX().toFloat() - a.GetX().toFloat());
	l2.t = l2.m * -c.GetX().toFloat() + c.GetY().toFloat();

	// LINE bc
	l3.m = (b.GetY().toFloat() - c.GetY().toFloat()) / (b.GetX().toFloat() - c.GetX().toFloat());
	l3.t = l3.m * -c.GetX().toFloat() + c.GetY().toFloat();

	//intersection of ab
	if (CorrectCross(Point((ray.t - l1.t) / (l1.m - ray.m), (((ray.t - l1.t)  / (l1.m - ray.m)) * ray.m + ray.t)), a, b, point, outside))
		result++;
	if (CorrectCross(Point((ray.t - l2.t)  / (l2.m - ray.m), (((ray.t - l2.t)  / (l2.m - ray.m)) * ray.m + ray.t)), a, c, point, outside))
		result++;
	if (CorrectCross(Point((ray.t - l3.t)  / (l3.m - ray.m), (((ray.t - l3.t)  / (l3.m - ray.m)) * ray.m + ray.t)), b, c, point, outside))
		result++;
	return (result % 2);
}