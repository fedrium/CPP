#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <math.h>
#include <iostream>

template <typename T> 
class Array 
{
	public:
		Array();
		Array(uint n);
		Array(const Array &c);
		Array<T> &operator=(const Array &c);
		~Array();
		int size();
		class OutOfBound : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		int &operator [] (int const n);
	private:
		T *ptr;
		unsigned int arraySize();
};

#endif