#include "bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		PresidentialPardonForm a("42 KL");
		bureaucrat b("Test", 1);
		std::cout << a;
		b.signForm(a);
		a.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}