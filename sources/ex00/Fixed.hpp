#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_FractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed &fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed& operator =(Fixed &fixed);
};

#endif