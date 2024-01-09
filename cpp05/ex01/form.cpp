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

std::string const form::getName()
{
	return (this->name);
}

bool form::getSign()
{
	return (this->sign);
}

int const &form::getGradeSign()
{
	return (this->gradeSign);
}

int const &form::getGradeExe()
{
	return (this->gradeExe);
}

const char *form::FormHigh::what() const throw()
{
	return "Grade too high.";
}

const char *form::FormLow::what() const throw()
{
	return "Grade too low.";
}

void form::beSigned(bureaucrat const &bu)
{
	if (bu.getGrade() <= this->getGradeSign())
		this->sign = true;
	else
		throw form::FormLow();
}

std::ostream &operator<<(std::ostream& os, form &Form)
{
	os << "Form " << Form.getName() <<  ", signed(" << Form.getSign() << ") needs " << Form.getGradeSign() << " and " << Form.getGradeExe() << " to execute it." << std::endl;
	return os;
}

form::form(std::string newName, int sign, int exe) : name(newName), gradeSign(sign), gradeExe(exe)
{
	std::cout << "Custom constructor called.";
	this->sign = false;
}