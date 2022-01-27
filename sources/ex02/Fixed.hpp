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
		
		static Fixed &min(Fixed &f1, Fixed &f2);
		static Fixed const &min( Fixed const &f1, Fixed const &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static Fixed const &max(Fixed const &f1, Fixed const &f2);

		Fixed& operator =(Fixed fixed);
		friend std::ostream& operator <<(std::ostream& out, const Fixed& f1);
		bool operator <(Fixed const &fixed);
		bool operator <=(Fixed const &fixed);
		bool operator >(Fixed const &fixed);
		bool operator >=(Fixed const &fixed);
		bool operator ==(Fixed const &fixed);
		bool operator !=(Fixed const &fixed);
		
		Fixed &operator ++();
		Fixed &operator --();
		Fixed operator ++(int);
		Fixed operator --(int);
		Fixed operator +(Fixed const &fixed) const;
		Fixed operator -(Fixed const &fixed) const;
		Fixed operator *(Fixed const &fixed) const;
		Fixed operator /(Fixed const &fixed) const;

};
#endif