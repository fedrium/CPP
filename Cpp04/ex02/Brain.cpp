#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain::Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea[i].assign("");
	}
}

Brain::Brain(const Brain &c)
{
	std::cout << "Brain::Copy constructor called" << std::endl;
	*this = c;
}

Brain	&Brain::operator=(const Brain &c)
{
	std::cout << "Brain::Copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->idea[i] = c.idea[i];
	}
	return *this;
}

std::string Brain::getIdea(int i) const
{
	return this->idea[i];
}

void	Brain::setIdea(int i, std::string input)
{
	this->idea[i] = input;
}

Brain::~Brain()
{
	std::cout << "Brain::Destructor called" << std::endl;
}
