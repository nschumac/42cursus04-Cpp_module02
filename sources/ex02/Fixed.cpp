#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
}

Fixed::Fixed(Fixed const &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
}

Fixed& Fixed::operator =(Fixed fixed)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(int const i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = i * 256;
}

Fixed::Fixed(float const f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)(std::roundf(f * 256));
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}
Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}
Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed& Fixed::operator ++()
{
	_fixedPointValue += 1;
	return (*this);
}
Fixed& Fixed::operator --()
{
	_fixedPointValue -= 1;
	return (*this);
}
Fixed Fixed::operator ++(int)
{
	Fixed temp = *this;
	_fixedPointValue += 1;
	return (temp);
}
Fixed Fixed::operator --(int)
{
	Fixed temp = *this;
	_fixedPointValue -= 1;
	return (temp);
}
Fixed Fixed::operator +(Fixed const &fixed) const
{
	return (Fixed(_fixedPointValue + fixed._fixedPointValue));
}
Fixed Fixed::operator -(Fixed const &fixed) const
{
	return (Fixed(_fixedPointValue - fixed._fixedPointValue));
}
Fixed Fixed::operator *(Fixed const &fixed) const
{
	return (Fixed((_fixedPointValue * fixed._fixedPointValue) / (256.f * 256.f)));
}
Fixed Fixed::operator /(Fixed const &fixed) const
{
	return (Fixed(std::roundf((_fixedPointValue * 256.f) / fixed._fixedPointValue) / 256.f));
}
bool Fixed::operator <(Fixed const &fixed)
{
	return (this->_fixedPointValue < fixed._fixedPointValue);
}
bool Fixed::operator <=(Fixed const &fixed)
{
	return (this->_fixedPointValue <= fixed._fixedPointValue);
}
bool Fixed::operator >(Fixed const &fixed)
{
	return (this->_fixedPointValue > fixed._fixedPointValue);
}
bool Fixed::operator >=(Fixed const &fixed)
{
	return (this->_fixedPointValue >= fixed._fixedPointValue);
}
bool Fixed::operator ==(Fixed const &fixed)
{
	return (this->_fixedPointValue == fixed._fixedPointValue);
}
bool Fixed::operator !=(Fixed const &fixed)
{
	return (this->_fixedPointValue != fixed._fixedPointValue);
}