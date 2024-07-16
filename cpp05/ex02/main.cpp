#include "bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		bureaucrat *One = new bureaucrat("high", 3);
		bureaucrat *Two = new bureaucrat("low", 133);

		AForm		*formA = new PresidentialPardonForm("Joe");
		AForm		*formB = new RobotomyRequestForm("Kaisen");
		AForm		*formC = new ShrubberyCreationForm("fortnite");

		std::cout << *One << std::endl;
		std::cout << *Two << std::endl;

		std::cout << *formA << std::endl;
		std::cout << *formB << std::endl;
		std::cout << *formC << std::endl;

		One->signForm(*formA);
		One->signForm(*formA);
		Two->execute(*formA);
		One->execute(*formA);

		Two->signForm(*formB);
		One->signForm(*formB);
		One->execute(*formB);
		One->execute(*formB);

		One->signForm(*formC);
		Two->execute(*formC);
		One->execute(*formC);

		delete One;
		delete Two;

		delete formA;
		delete formB;
		delete formC;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}