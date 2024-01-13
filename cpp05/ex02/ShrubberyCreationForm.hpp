#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "form.hpp"

class ShruberryCreationForm : public AForm
{
	public:
		ShruberryCreationForm();
		ShruberryCreationForm(const ShruberryCreationForm &c);
		ShruberryCreationForm &operator=(const ShruberryCreationForm &c);
		~ShruberryCreationForm();
		ShruberryCreationForm(std::string target);
	private:
		
};

#endif