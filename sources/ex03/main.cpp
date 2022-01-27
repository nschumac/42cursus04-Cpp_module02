#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	
	Point const A(1.f, 0.f);
	Point const B(0.f, 1.f);
	Point const C(-1.f, 0.f);
	Point const point(0.f, 0.99f);

	if (bsp(A, B, C, point))
		std::cout << "You are godlike";
	else
		std::cout << "FUCKING IDIOT";

	return 0; 
}