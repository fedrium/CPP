#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat::Default constructor called" << std::endl;
	this->type = "Dog";
}

WrongCat::WrongCat(const WrongCat &c) : WrongAnimal(c)
{
	std::cout << "WrongCat::Copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat::Copy assignment operator called" << std::endl;
	this->type = c.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat::Destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "bark~" << std::endl;
}