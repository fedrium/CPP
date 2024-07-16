#include "bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	bureaucrat	*workerA = new bureaucrat("William", 5);

	Intern		*internA = new Intern();

	AForm		*formA = internA->makeForm("presidentialpardonform", "bob");
	AForm		*formB = internA->makeForm("robotomyrequestform", "elon musk");
	AForm		*formC = internA->makeForm("shrubberycreationform", "mars");

	try
	{
		AForm		*formThatDoesNotExist = internA->makeForm("sus", "amogus");
		delete formThatDoesNotExist;
	}
	catch (const Intern::formNotExist& err)
	{
		std::cerr << err.what() << std::endl;
		
	}

	std::cout << *workerA << std::endl;

	std::cout << *formA << std::endl;
	std::cout << *formB << std::endl;
	std::cout << *formC << std::endl;

	delete workerA;
	delete internA;

	delete formA;
	delete formB;
	delete formC;

	return (0);
}