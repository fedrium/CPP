#include "form.hpp"
#include "bureaucrat.hpp"

form::form() :  name("NULL"), gradeSign(1), gradeExe(1)
{
	std::cout << "form::Default constructor called" << std::endl;
	this->sign = false;
}

form::form(const form &c) : name(c.name), gradeSign(c.gradeSign), gradeExe(c.gradeExe)
{
	std::cout << "form::Copy constructor called" << std::endl;
	*this = c;
}

form &form::operator=(const form &c)
{
	std::cout << "form::Copy assignment operator called" << std::endl;
	this->sign = c.sign;
	return (*this);
}

form::~form()
{
	std::cout << "Destructor called" << std::endl;
}

std::string form::getName() const
{
	return (this->name);
}

bool form::getSign() const
{
	return (this->sign);
}

int form::getGradeSign() const
{
	return (this->gradeSign);
}

int form::getGradeExe() const
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

std::ostream &operator<<(std::ostream& os, const form &Form)
{
	if (Form.getSign() == false)
		os << "Form " << Form.getName() <<  ", not signed needs grade " << Form.getGradeSign() << " to sign and " << Form.getGradeExe() << " to execute it." << std::endl;
	else
		os << "Form " << Form.getName() <<  ", signed needs " << Form.getGradeSign() << " to sign and " << Form.getGradeExe() << " to execute it." << std::endl;
	return os;
}

form::form(std::string newName, int sign, int exe) : name(newName), gradeSign(sign), gradeExe(exe)
{
	std::cout << "Custom constructor called." << std::endl;
	this->sign = false;
	if ()
}