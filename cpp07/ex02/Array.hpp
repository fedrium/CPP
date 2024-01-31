#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <math.h>
#include <iostream>

template <typename T> 
class Array 
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &c);
		Array &operator=(const Array &c);
		~Array();
		int size();
		class OutOfBound : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		T &operator [] (int const n);
	private:
		T *ptr;
		unsigned int arraySize;
};

#include "Array.tpp"

#endif