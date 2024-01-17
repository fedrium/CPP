#include "misc.hpp"

Base *generate(void)
{
	int ran;

	srand(time(0));
	ran = rand() % 3;
	if (ran == 0)
		return (new A());
	if (ran == 1)
		return (new B());
	if (ran == 2)
		return (new C());
	return(NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "its a A class." << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "its a B class." << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "its a C class." << std::endl;
	else
		std::cout << "invalid input." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		Base &tmp = dynamic_cast<A &>(p);
		(void)tmp;
		std::cout << "its A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{

	}
	try
	{
		Base &tmp = dynamic_cast<B &>(p);
		(void)tmp;
		std::cout << "its B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{

	}
	try
	{
		Base &tmp = dynamic_cast<C &>(p);
		(void)tmp;
		std::cout << "its C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{

	}
	std::cout << "invalid input." << std::endl;
}