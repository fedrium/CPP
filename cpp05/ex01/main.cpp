#include "bureaucrat.hpp"

int	main()
{
	try
	{
		bureaucrat b("Man", 90);
		std::cout << b;
		form a("Test", 100, 140);
		std::cout << a;
		b.signForm(a);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}