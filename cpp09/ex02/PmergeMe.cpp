#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &c)
{
	(void)c;
}

PmergeMe PmergeMe::operator=(const PmergeMe &c)
{
	(void)c;
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::insert_value(std::vector<int> vec)
{
	std::vector<int>::iterator ptr = vec.begin();

	for (; ptr != vec.end(); ptr++)
		this->v.push_back(*ptr);
}