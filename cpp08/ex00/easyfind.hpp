#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>

class notFound : public std::exception
{
	public:
		const char* what() const throw();
};

template <typename T> typename T::iterator easyfind(T x, int n);

#include "easyfind.tpp"

#endif