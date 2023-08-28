#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal::Default constructor called" << std::endl;
}

Animal::Animal(const Animal &c)
{
	std::cout << "Animal::Copy constructor called" << std::endl;
	*this = c;
}

Animal	&Animal::operator=(const Animal &c)
{
	std::cout << "Animal::Copy assignment operator called" << std::endl;
	this->type = c.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal::Destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Incomprehensible noises~" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}