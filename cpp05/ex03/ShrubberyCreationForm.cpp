#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("UNKnOWN")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &c) : AForm(c), target(c.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &c)
{
	std::cout << "Copy assignment called" << std::endl;
	this->target = c.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("ShrubberyCreationForm", 145, 137), target(newTarget)
{
	std::cout << "Constructor callled." << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void	ShrubberyCreationForm::exe() const
{
	std::string tree;
	tree =   "       _-_ \n    /~~   ~~\\ \n /~~         ~~\\ \n{               } \n \\  _-     -_  /\n   ~  \\ //  ~ \n - -   | | _- _ \n   _ -  | |   -_ \n       // \\ \n";

	std::fstream file;
	file.open((std::string(target).append("_shrubbery")).c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
	file << tree;
	file.close();
}

AForm *ShrubberyCreationForm::intern(std::string target)
{
	return (new ShrubberyCreationForm(target));
}