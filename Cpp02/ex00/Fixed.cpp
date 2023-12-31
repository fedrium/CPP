#include "Fixed.hpp"

Fixed::Fixed()
{
    fpvn = 0;
    std::cout << "Default constructor called" << std::endl;
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