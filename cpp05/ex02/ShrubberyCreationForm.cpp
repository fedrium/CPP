#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm::Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &c)
{
	std::cout << "ShrubberyCreationForm::Copy constructor called" << std::endl;
	*this = c;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &c)
{
	std::cout << "ShrubberyCreationForm::Copy assignment operator called" << std::endl;
	this->sign = c.sign;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}