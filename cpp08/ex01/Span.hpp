#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <bits/stdc++.h> 

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &c);
		Span operator=(const Span &c);
		~Span();
		class NumberOverflow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NumberLow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void addNumber(unsigned int n);
		void addNumber(int *array, unsigned int size);
		int shortestSpan();
		int longestSpan();
		void fillvec();
	private:
		std::vector<int> 	array;
		unsigned int 		size;
};

#endif