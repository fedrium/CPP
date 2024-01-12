#include "form.hpp"
#include "bureaucrat.hpp"

AForm::AForm() :  name("NULL"), gradeSign(1), gradeExe(1)
{
	std::cout << "AForm::Default constructor called" << std::endl;
	this->sign = false;
}

AForm::AForm(const AForm &c) : name(c.name), gradeSign(c.gradeSign), gradeExe(c.gradeExe)
{
	std::cout << "AForm::Copy constructor called" << std::endl;
	*this = c;
}

AForm &AForm::operator=(const AForm &c)
{
	std::cout << "AForm::Copy assignment operator called" << std::endl;
	this->sign = c.sign;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (this->sign);
}

int AForm::getGradeSign() const
{
	return (this->gradeSign);
}

int AForm::getGradeExe() const
{
	return (this->gradeExe);
}

const char *AForm::AFormHigh::what() const throw()
{
	return "Grade too high.";
}

const char *AForm::AFormLow::what() const throw()
{
	return "Grade too low.";
}

void AForm::beSigned(bureaucrat const &bu)
{
	if (bu.getGrade() <= this->getGradeSign())
		this->sign = true;
	else
		throw AForm::AFormLow();
}

std::ostream &operator<<(std::ostream& os, const AForm &AForm)
{
	if (AForm.getSign() == false)
		os << "AForm " << AForm.getName() <<  ", not signed needs grade " << AForm.getGradeSign() << " to sign and " << AForm.getGradeExe() << " to execute it." << std::endl;
	else
		os << "AForm " << AForm.getName() <<  ", signed needs " << AForm.getGradeSign() << " to sign and " << AForm.getGradeExe() << " to execute it." << std::endl;
	return os;
}

AForm::AForm(std::string newName, int sign, int exe) : name(newName), gradeSign(sign), gradeExe(exe)
{
	std::cout << "Custom constructor called." << std::endl;
	this->sign = false;
	if (sign  < 1 || exe < 1)
		throw AForm::AFormHigh();
	else if (sign > 150 || exe > 150)
		throw AForm::AFormLow();
}