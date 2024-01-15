#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &c) : AForm(c), target(c.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &c)
{
	std::cout << "Copy assignment callled" << std::endl;
	this->target = c.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor callled" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget) : AForm("PresidentialPardonForm", 45, 5), target(newTarget)
{
	std::cout << "Constructor called." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void 	PresidentialPardonForm::exe() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm *PresidentialPardonForm::intern(std::string target)
{
	return (new PresidentialPardonForm(target));
}