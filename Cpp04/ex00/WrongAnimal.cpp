#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal::Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &c)
{
	std::cout << "WrongAnimal::Copy constructor called" << std::endl;
	*this = c;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &c)
{
	std::cout << "WrongAnimal::Copy assignment operator called" << std::endl;
	this->type = c.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal::Destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Incomprehensible noises~" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}