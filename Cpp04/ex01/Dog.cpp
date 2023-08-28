#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog::Default constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &c) : Animal (c)
{
	std::cout << "Dog::Copy constructor called" << std::endl;
	brain = new Brain();
	*this = c;
}

Dog	&Dog::operator=(const Dog &c)
{
	std::cout << "Dog::Copy assignment operator called" << std::endl;
	this->type = c.type;
	for (int i = 0; i < 100; i++)
	{
		this->setIdea(i, c.getIdea(i));
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog::Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "bark~" << std::endl;
}

std::string Dog::getIdea(int i) const
{
	return(brain->getIdea(i));
}

void	Dog::setIdea(int i, std::string input)
{
	brain->setIdea(i, input);
}