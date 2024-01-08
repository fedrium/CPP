#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <string.h>

class GradeHigh : public std::exception {
	public:
		virtual const char	*what() const throw();
};

class GradeLow : public std::exception {
	public:
		virtual const char	*what() const throw();
};

class bureaucrat{
	public:
		bureaucrat();
		bureaucrat(const bureaucrat &c);
		bureaucrat &operator=(const bureaucrat &c);
		~bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		GradeHigh GradeTooHighException;
		GradeLow GradeTooLowException;
		bureaucrat(std::string name, int grade);
		void	increment();
		void	decrement();
		void	signForm();
	private:
		int grade;
		std::string name;
};

std::ostream& operator<<(std::ostream& os, const bureaucrat& bu);

#endif