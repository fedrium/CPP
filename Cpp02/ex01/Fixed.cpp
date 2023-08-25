#include "Fixed.hpp"

Fixed::Fixed(const int i)
{
    this->setRawBits(i);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    this->setRawBits(f);
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed &c)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = c;
}

Fixed &Fixed::operator=(Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->fpvn = copy.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
    out << c.getRawBits();
}

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
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

