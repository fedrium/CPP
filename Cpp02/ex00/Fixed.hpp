#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed &c);
		Fixed &operator=(Fixed &copy);
		~Fixed();
		int		getRawBits(void);
		void	setRawBits(int const var);
	private:
		int	fpvn;
		static const int fb;
};

#endif