#include "easyfind.hpp"

const char* notFound::what() const throw()
{
	return ("It is not found.");
}

template <typename T> typename T::iterator easyfind(T x, int n)
{
	typename T::iterator ptr = std::find(x.begin(), x.end(), n);

	if (ptr == x.end())
		throw (notFound());
	return (ptr);
}