#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "form.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &c);
		Intern operator=(const Intern &c);
		~Intern();
		AForm* makeForm(std::string formName, std::string target);
		std::string cleanString(std::string str);
		class formNotExist : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif