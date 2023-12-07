#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>

class bureaucrat : public std::exception{
	public:
		std::string	getName();
		int			getGrade();
	private:
		const std::string name;
		int grade;
};

#endif