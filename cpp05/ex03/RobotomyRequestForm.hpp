#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &c);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &c);
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string newTarget);
		void	exe() const;
		std::string getTarget() const;
		static AForm *intern(std::string target);
	private:
		std::string target;
};

#endif