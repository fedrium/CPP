#include "AForm.hpp"
#include "bureaucrat.hpp"

AForm::AForm() :  name("NULL"), gradeSign(1), gradeExe(1)
{
	std::cout << "Default constructor called" << std::endl;
	this->sign = false;
}

AForm::AForm(const AForm &c) : name(c.name), gradeSign(c.gradeSign), gradeExe(c.gradeExe)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = c;
}

AForm &AForm::operator=(const AForm &c)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	return "Grade too high.\n";
}

const char *AForm::AFormLow::what() const throw()
{
	return "Grade too low.\n";
}

const char *AForm::AFormnotSigned::what() const throw()
{
	return "Form is not signed.\n";
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
		os << "Form " << AForm.getName() <<  ", not signed needs grade " << AForm.getGradeSign() << " to sign and " << AForm.getGradeExe() << " to execute it." << std::endl;
	else
		os << "Form " << AForm.getName() <<  ", signed needs " << AForm.getGradeSign() << " to sign and " << AForm.getGradeExe() << " to execute it." << std::endl;
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

void	AForm::execute(bureaucrat const &executor) const
{
	if (this->sign == false)
		throw AForm::AFormnotSigned();
	if (executor.getGrade() > getGradeExe())
		throw AForm::AFormLow();
	exe();
}