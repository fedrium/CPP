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

const char *bureaucrat::GradeHigh::what() const throw()
{
	return "Grade too high.";
}

const char *bureaucrat::GradeLow::what() const throw()
{
	return "Grade too low.";
}

void	bureaucrat::increment()
{
	this->grade--;
	if (this->grade < 1)
		throw bureaucrat::GradeHigh();
}

void	bureaucrat::decrement()
{
	this->grade++;
	if (this->grade > 150)
		throw bureaucrat::GradeLow();
}

std::ostream& operator<<(std::ostream& os, const bureaucrat& bu)
{
	os << bu.getName() <<  " , bureaucrat grade " << bu.getGrade() << std::endl;
	return os;
}

bureaucrat::bureaucrat(std::string Name, int grade) : name(Name)
{
	std::cout << "Custom constructor called" << std::endl;
	this->grade = grade;
	if (this->grade > 150)
		throw bureaucrat::GradeLow();
	if (this->grade < 1)
		throw bureaucrat::GradeHigh();
}

void	bureaucrat::signForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->name << " signed " << AForm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void	bureaucrat::execute(AForm &aform)
{
	try
	{
		aform.execute(*this);
	}
	catch (const AForm::AFormnotSigned &err)
	{
		std::cerr << "Bureaucrat: " << getName() << " couldn't execute " << aform.getName() << " because form was not signed" << std::endl;
		return ;
	}
	catch (const AForm::AFormLow &err)
	{
		std::cerr << "Bureaucrat: " << getName() << " couldn't execute " << aform.getName() <<  " because grade was too low" << std::endl;
		return ;
	}
	std::cout << "Bureaucrat: " << getName() << " executed " << aform.getName() << std::endl;
}