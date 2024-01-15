#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &c) : AForm(c), target(c.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &c)
{
	std::cout << "Copy assignment called" << std::endl;
	this->target = c.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget) : AForm("RobotomyRequestForm", 72, 45), target(newTarget)
{
	std::cout << "Constructor callled." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void	RobotomyRequestForm::exe() const
{
	int num;

	std::cout << "Brrrrrrrrrrrrrrrrrrrrrrrrr-\n";
	srand(time(0));
	num = std::rand() % 2;
	if (num == 0)
		std::cout << target << " has been successful robotomized.\n";
	else
		std::cout << "Robotomy failed on " << target << ".\n";
}

AForm *RobotomyRequestForm::intern(std::string target)
{
	return (new RobotomyRequestForm(target));
}