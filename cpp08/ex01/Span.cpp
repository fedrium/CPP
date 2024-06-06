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

const char* Span::NumberLow::what() const throw()
{
	return ("Insufficinet number in array.\n");
}

void Span::addNumber(unsigned int n)
{
	if (array.size() + 1 > size)
		throw (Span::NumberOverflow());
	array.insert(array.end(), n);
}

void Span::addNumber(int *iarray, unsigned int isize)
{
	if (isize > size || array.size() + 1 > size || (isize + array.size()) > size)
		throw (Span::NumberOverflow());
	array.insert(array.end(), iarray, iarray + isize);
}

unsigned int diff(int a, int b)
{
	if (a > b)
		return ((unsigned int) a - (unsigned int) b);
	else
		return ((unsigned int) b - (unsigned int) a);
}

int Span::shortestSpan()
{
	if (array.size() < 2)
		throw (Span::NumberLow());

	std::vector<int> temp = array;
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin(), diff);
	// for (std::vector<int>::iterator i = temp.begin(); i < temp.end(); i++)
	// 	std::cout << "temp: " << *i << std::endl;
	return (*std::min_element(temp.begin(), temp.end()));
}

int Span::longestSpan()
{
	if (array.size() < 2)
		throw (Span::NumberLow());
	
	int temp = (*(std::max_element(array.begin(), array.end())) - *(std::min_element(array.begin(), array.end())));
	return temp;
}

void Span::fillvec()
{
	std::srand(unsigned(std::time(NULL)));
	std::vector<int> v(size);
	std::generate(v.begin(), v.end(), std::rand);
	array = v;
	for (std::vector<int>::iterator i = array.begin(); i < array.end(); i++)
		std::cout << "temp: " << *i << std::endl;
}