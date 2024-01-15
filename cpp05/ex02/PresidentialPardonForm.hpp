#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "form.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &c);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &c);
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string newTarget);
		void	exe() const;
		std::string getTarget() const;
	private:
		std::string target;
};

#endif