#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
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
		void addNumber(unsigned int n);
		int shortestSpan();
		// int longestSpan();
	private:
		std::vector<int> 	array;
		int 				size;
};

#endif