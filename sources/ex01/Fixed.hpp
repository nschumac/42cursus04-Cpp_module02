#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_FractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed &fixed);
		Fixed(Fixed const &fixed);
		Fixed(int const i);
		Fixed(float const f);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed& operator =(Fixed fixed);
		friend std::ostream& operator <<(std::ostream& out, const Fixed& f1);
};

#endif