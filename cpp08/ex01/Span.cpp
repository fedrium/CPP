#include "Span.hpp"

Span::Span()
{
	std::cout << "Default constructor" << std::endl;
}

Span::Span(unsigned int N)
{
	this->size = N;
}

Span::Span(const Span &c)
{
	(void)c;
	this->size = c.size;
}

Span Span::operator=(const Span &c)
{
	(void)c;
	return (*this);
}

Span::~Span()
{
	std::cout << "Destructor called";
}

const char* Span::NumberOverflow::what() const throw()
{
	return ("Number exceeds maximum quota.\n");
}

void Span::addNumber(unsigned int n)
{
	if (array.size() + 1 > n)
		throw (Span::NumberOverflow());
	array.insert(array.end(), n);
}

int Span::shortestSpan()
{
	std::sort(array.begin(), array.end());
	std::cout << "Sorted \n"; 
    for (int i = 0; i < (int)array.size(); i++)
	{
        std::cout << array[i] << " ";
	}
	return (array[1] - array[0]);
}