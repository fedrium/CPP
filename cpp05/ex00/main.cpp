#include "bureaucrat.hpp"

int	main()
{
	try
	{
		bureaucrat b("A", 150);
		b.decrement();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		bureaucrat c("C", 1);
		c.increment();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	bureaucrat a("B", 120);
	std::cout << a;
	return 0;
}