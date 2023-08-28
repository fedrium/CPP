#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog::Default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &c) : Animal (c)
{
	std::cout << "Dog::Copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &c)
{
	std::cout << "Dog::Copy assignment operator called" << std::endl;
	this->type = c.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog::Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "bark~" << std::endl;
}