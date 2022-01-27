#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
}

Fixed& Fixed::operator =(Fixed fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(int const i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = i * 256;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)(std::roundf(f * 256));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator <<(std::ostream& out, const Fixed& fixed)
{
	out << (float)(fixed._fixedPointValue / 256.f);
	return (out);
}

float Fixed::toFloat( void ) const
{
	return (this->_fixedPointValue / 256.f);
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointValue / 256);
}
