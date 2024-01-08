#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string.h>
#include <bureaucrat.hpp>

class FormHigh : public std::exception {
	public:
		virtual const char	*what() const throw();
};

class FormLow : public std::exception {
	public:
		virtual const char	*what() const throw();
};

class form{
	public:
		form();
		form(const form &c);
		form &operator=(const form &c);
		~form();
		std::string getName();
		bool getSign();
		const int getGradeSign();
		const int getGradeExe();
		void	beSigned(bureaucrat bu);
		FormHigh GradeTooHighException;
		FormLow GradeTooLowException;
	private:
		const std::string name;
		bool sign;
		const int gradeSign;
		const int gradeExe;
};

#endif