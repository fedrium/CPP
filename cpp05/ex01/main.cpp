#include "bureaucrat.hpp"

int	main()
{
	try
	{
		bureaucrat b("A", 150);
		if (b.getGrade() < 1)
			throw b.GradeTooHighException;
		if (b.getGrade() > 150)
			throw b.GradeTooLowException;
		b.decrement();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	bureaucrat a("B", 120);
	std::cout << a;
	return 0;
}