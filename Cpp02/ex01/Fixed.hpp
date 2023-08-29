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
	private:
		int	fpvn;
		static const int fb;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif

// cout << str
// "aksdlsadj"
//cout << class
// class: name, number, 