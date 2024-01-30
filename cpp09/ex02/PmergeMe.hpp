#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <utility>
#include <list>
#include <time.h>

using std::endl;
using std::cout;
using std::string;

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &c);
		PmergeMe operator=(const PmergeMe &c);
		~PmergeMe();
		void Sort(std::vector<int> vec);
		void Sort(std::list<int> list);
		void insert_value(std::vector<int> vec);
		void insert_value_l(std::vector<int> vec);
		void printVec();
	private:
		std::vector<int> v;
		std::list<int> l;
};

#endif