#include "bureaucrat.hpp"

bureaucrat::bureaucrat() : name("NULL")
{
	std::cout << "bureaucrat::Default constructor called" << std::endl;
	this->grade = 150;
}

bureaucrat::bureaucrat(const bureaucrat &c) : name(c.name)
{
	std::cout << "bureaucrat::Copy constructor called" << std::endl;
	this->grade = c.grade;
}

bureaucrat &bureaucrat::operator=(const bureaucrat &c)
{
	std::cout << "bureaucrat::Copy assignment operator called" << std::endl;
	this->grade = c.grade;
	return (*this);
}

bureaucrat::~bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

std::string bureaucrat::getName() const
{
	return name;
}

int bureaucrat::getGrade() const
{
	return grade;
}

const char *GradeHigh::what() const throw()
{
	return "Grade too high.\n";
}

const char *GradeLow::what() const throw()
{
	return "Grade too low.\n";
}

void	bureaucrat::increment()
{
	this->grade--;
	if (this->grade < 1)
		throw this->GradeTooHighException;
}

void	bureaucrat::decrement()
{
	this->grade++;
	if (this->grade > 150)
		throw this->GradeTooLowException;
}

std::ostream& operator<<(std::ostream& os, const bureaucrat& bu)
{
	os << bu.getName() <<  " , bureaucrat grade " << bu.getGrade() << std::endl;
	return os;
}

bureaucrat::bureaucrat(std::string Name, int grade) : name(Name)
{
	this->grade = grade;
	if (this->grade > 150)
		throw this->GradeTooLowException;
	if (this->grade < 1)
		throw this->GradeTooHighException;
}