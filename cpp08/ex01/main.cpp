#include "Span.hpp"

int main()
{
	Span span;
	span.addNumber(1);
	span.addNumber(3);
	span.addNumber(135);
	span.addNumber(69);

	std::cout << span.shortestSpan();
}