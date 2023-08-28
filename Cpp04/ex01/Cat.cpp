#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat::Default constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &c) : Animal(c)
{
	std::cout << "Cat::Copy constructor called" << std::endl;
	brain = new Brain();
	*this = c;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat::Copy assignment operator called" << std::endl;
	this->type = c.type;
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(i, c.getIdea(i));
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat::Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow~" << std::endl;
}

std::string Cat::getIdea(int i) const
{
	return (brain->getIdea(i));
}

void	Cat::setIdea(int i, std::string input)
{
	brain->setIdea(i, input);
}