#include "form.hpp"
#include "bureaucrat.hpp"

Form::Form() :  name("NULL"), gradeSign(1), gradeExe(1)
{
	std::cout << "Form::Default constructor called" << std::endl;
	this->sign = false;
}

Form::Form(const Form &c) : name(c.name), gradeSign(c.gradeSign), gradeExe(c.gradeExe)
{
	std::cout << "Form::Copy constructor called" << std::endl;
	*this = c;
}

Form &Form::operator=(const Form &c)
{
	std::cout << "Form::Copy assignment operator called" << std::endl;
	this->sign = c.sign;
	return (*this);
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int Form::getGradeSign() const
{
	return (this->gradeSign);
}

int Form::getGradeExe() const
{
	return (this->gradeExe);
}

const char *Form::FormHigh::what() const throw()
{
	return "Grade too high.";
}

const char *Form::FormLow::what() const throw()
{
	return "Grade too low.";
}

void Form::beSigned(bureaucrat const &bu)
{
	if (bu.getGrade() <= this->getGradeSign())
		this->sign = true;
	else
		throw Form::FormLow();
}

std::ostream &operator<<(std::ostream& os, const Form &Form)
{
	if (Form.getSign() == false)
		os << "Form " << Form.getName() <<  ", not signed needs grade " << Form.getGradeSign() << " to sign and " << Form.getGradeExe() << " to execute it." << std::endl;
	else
		os << "Form " << Form.getName() <<  ", signed needs " << Form.getGradeSign() << " to sign and " << Form.getGradeExe() << " to execute it." << std::endl;
	return os;
}

Form::Form(std::string newName, int sign, int exe) : name(newName), gradeSign(sign), gradeExe(exe)
{
	std::cout << "Custom constructor called." << std::endl;
	this->sign = false;
	if (sign  < 1 || exe < 1)
		throw Form::FormHigh();
	else if (sign > 150 || exe > 150)
		throw Form::FormLow();
}