#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &c)
{
	(void) c;
}

Intern::~Intern()
{

}

Intern Intern::operator=(const Intern &c)
{
	(void) c;
	return (*this);
}

std::string Intern::cleanString(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		str[i] = tolower(str[i]);
		if (str[i] == ' ')
		{
			str.erase(i, 1);
			i--;
		}
	}
	return (str);
}

const char *Intern::formNotExist::what() const throw()
{
	return "Form does not exist.\n";
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm *(*funcptr[3])(std::string) = {&RobotomyRequestForm::intern, &PresidentialPardonForm::intern, &ShrubberyCreationForm::intern};
	std::string names[3] = {"robotomyrequestform", "presidentialpardonform", "shrubberycreationform"};
	AForm *form;

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (cleanString(formName) == names[i])
			{
				form = (*funcptr[i])(target);
				std::cout << "Intern: Intern creates " << formName << std::endl;
				return (form);
			}
		}
		throw Intern::formNotExist();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
		return (NULL);
	}
}

