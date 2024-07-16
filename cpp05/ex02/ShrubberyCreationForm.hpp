#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &c);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &c);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string newTarget);
		void	exe() const;
		std::string getTarget() const;
	private:
		std::string target;
};

#endif