
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int holder;
		static const int _fixed = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed &);
		Fixed(const int i_fixed);
		Fixed(const float f_fixed);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed& data) const;
		bool operator<(const Fixed& data) const;
		bool operator>=(const Fixed& data) const;
		bool operator<=(const Fixed& data) const;
		bool operator==(const Fixed& data) const;
		bool operator!=(const Fixed& data) const;

		Fixed operator+(const Fixed& data) const;
		Fixed operator-(const Fixed& data) const;
		Fixed operator*(const Fixed& data) const;
		Fixed operator/(const Fixed& data) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		
		static Fixed &min(Fixed& x, Fixed& y);
		static Fixed &max(Fixed& x, Fixed& y);
		const static Fixed &min(const Fixed& x, const Fixed& y);
		const static Fixed &max(const Fixed& x, const Fixed& y);
};
	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif