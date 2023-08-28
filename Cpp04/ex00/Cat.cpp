#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat::Default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &c) : Animal(c)
{
	std::cout << "Cat::Copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat::Copy assignment operator called" << std::endl;
	this->type = c.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat::Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow~" << std::endl;
}