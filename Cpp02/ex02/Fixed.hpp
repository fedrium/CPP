#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &c);
		Fixed &operator=(const Fixed &copy);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const var);
		float	toFloat(void) const;
		int		toInt(void) const;

        bool    operator>(Fixed const& c);
        bool    operator<(Fixed const& c);
        bool    operator>=(Fixed const& c);
        bool    operator<=(Fixed const& c);
        bool    operator==(Fixed const& c);
        bool    operator!=(Fixed const& c);

        Fixed   operator+(Fixed const& c);
        Fixed   operator-(Fixed const& c);
        Fixed   operator*(Fixed const& c);
        Fixed   operator/(Fixed const& c);

        Fixed   &operator++(int);
        Fixed   &operator--(int);

        Fixed   operator++();
        Fixed   operator--();

        static int min(Fixed &c1, Fixed &c2);
        static int max(const Fixed &c1, const Fixed &c2);
        static int min2(Fixed &c1, Fixed &c2);
        static int max2(const Fixed &c1, const Fixed &c2);
	private:
		int	fpvn;
		static const int fb;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif