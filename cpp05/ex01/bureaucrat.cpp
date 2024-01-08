#include "bureaucrat.hpp"

bureaucrat::bureaucrat()
{
	std::cout << "bureaucrat::Default constructor called" << std::endl;
	this->name = "NULL";
	this->grade = 0;
}

bureaucrat::bureaucrat(const bureaucrat &c)
{
	std::cout << "bureaucrat::Copy constructor called" << std::endl;
	*this = c;
}

bureaucrat &bureaucrat::operator=(const bureaucrat &c)
{
	std::cout << "bureaucrat::Copy assignment operator called" << std::endl;
	this->grade = c.getGrade();
	this->name = c.getName();
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
	return "Grade too high.";
}

const char *GradeLow::what() const throw()
{
	return "Grade too low.";
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

void	bureaucrat::signForm()
{
	
}

std::ostream& operator<<(std::ostream& os, const bureaucrat& bu)
{
	os << bu.getName() <<  " , bureaucrat grade " << bu.getGrade() << std::endl;
	return os;
}

bureaucrat::bureaucrat(std::string name, int grade)
{
	std::cout << "Custom constructor called" << std::endl;
	this->grade = grade;
	this->name = name;
}