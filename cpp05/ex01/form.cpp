#include "form.hpp"

form::form() : gradeExe(1), gradeSign(1), name("NULL")
{
	std::cout << "form::Default constructor called" << std::endl;
	this->sign = false;
}

form::form(const form &c) : name(c.name), gradeExe(c.gradeExe), gradeSign(c.gradeSign)
{
	std::cout << "form::Copy constructor called" << std::endl;
	*this = c;
}

form &form::operator=(const form &c)
{
	std::cout << "form::Copy assignment operator called" << std::endl;
	return (*this);
}

form::~form()
{
	std::cout << "Destructor called" << std::endl;
}

std::string form::getName()
{
	return (this->name);
}

bool form::getSign()
{
	return (this->sign);
}

const int form::getGradeSign()
{
	return (this->gradeSign);
}

const int form::getGradeExe()
{
	return (this->gradeExe);
}

const char *FormHigh::what() const throw()
{
	return "Grade too high.";
}

const char *FormLow::what() const throw()
{
	return "Grade too low.";
}

void form::beSigned(bureaucrat bu)
{
	if (bu.getGrade() <= this->getGradeSign())
		this->sign = true;
	else
		throw this->GradeTooLowException;
}

