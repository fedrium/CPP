#include "Fixed.hpp"

const int Fixed::fb = 8;

Fixed::Fixed(const int i)
{
    this->fpvn = i * (1 << this->fb);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    this->fpvn = roundf(f * (1 << this->fb));
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
    return(this->fpvn / (float)(1 << this->fb));
}

int     Fixed::toInt(void) const
{
    return (this->fpvn / (1 << this->fb));
}

