#include "Fixed.hpp"

const int Fixed::fb = 8;

Fixed::Fixed(const int i)
{
	this->fpvn = i * (1 << this->fb);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	this->fpvn = std::roundf(f * (1 << this->fb));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed()
{
	this->fpvn = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &c)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = c;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->fpvn = copy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return out;
}

/*ex02 functions*/
bool    Fixed::operator>(Fixed const& c) const
{
	return (fpvn > c.fpvn);
}

bool    Fixed::operator<(Fixed const& c) const
{
	return (fpvn < c.fpvn);
}

bool    Fixed::operator<=(Fixed const& c) const
{
	return (fpvn <= c.fpvn);
}

bool    Fixed::operator>=(Fixed const& c) const
{
	return (fpvn >= c.fpvn);
}

bool    Fixed::operator==(Fixed const& c) const
{
	return (fpvn == c.fpvn);
}

bool    Fixed::operator!=(Fixed const& c) const
{
	return (fpvn != c.fpvn);
}

/*+-*/
Fixed   Fixed::operator+(Fixed const& c)
{
	float one = toFloat();
	float two = c.toFloat();
	return (one + two);
}

Fixed   Fixed::operator-(Fixed const& c)
{
	float one = toFloat();
	float two = c.toFloat();
	return (one - two);
}

Fixed   Fixed::operator*(Fixed const& c)
{
	float one = toFloat();
	float two = c.toFloat();
	return (one * two);
}

Fixed   Fixed::operator/(Fixed const& c)
{
	float one = toFloat();
	float two = c.toFloat();
	return (one / two);
}

/*doubles*/
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fpvn += 1;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fpvn -= 1;
	return (temp);
}

Fixed	Fixed::operator++()
{
	this->fpvn += 1;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->fpvn += 1;
	return (*this);
}

/*minmax*/
Fixed Fixed::min(Fixed &c1, Fixed &c2)
{
	if (c1 > c2)
		return(c2);
	else
		return(c1);
}

Fixed Fixed::min(const Fixed &c1, const Fixed &c2)
{
	if (c1 > c2)
		return (c2);
	else
		return (c1);
}

Fixed Fixed::max(Fixed &c1, Fixed &c2)
{
	if (c1 < c2)
		return(c2);
	else
		return(c1);
}

Fixed Fixed::max(const Fixed &c1, const Fixed &c2)
{
	if (c1 < c2)
		return (c2);
	else
		return (c1);
}

/*getsetter*/
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fpvn);
}

void    Fixed::setRawBits(int const raw) 
{
	fpvn = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float   Fixed::toFloat(void) const
{
	return((float)this->fpvn / (float)(1 << this->fb));
}

int     Fixed::toInt(void) const
{
	return ((int)this->fpvn / (int)(1 << this->fb));
}

