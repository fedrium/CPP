#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <string.h>
#include "form.hpp"


class bureaucrat{
	public:
		bureaucrat();
		bureaucrat(const bureaucrat &c);
		bureaucrat &operator=(const bureaucrat &c);
		~bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		class GradeHigh : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeLow : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		bureaucrat(std::string name, int grade);
		void	increment();
		void	decrement();
		void	signForm(form &Form);
	private:
		int grade;
		std::string name;
};

std::ostream& operator<<(std::ostream& os, const bureaucrat& bu);

#endif