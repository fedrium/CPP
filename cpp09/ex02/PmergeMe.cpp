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

void vector_split(std::vector<int> vec)
{
	std::vector<std::pair<int, int> > pair_vec;
	std::vector<std::pair<int, int> >::iterator pair_vec_ptr;
	std::vector<int>::iterator ptr;

	
}

void PmergeMe::insert_value(std::vector<int> vec)
{
	std::vector<int>::iterator ptr = vec.begin();

	for (; ptr != vec.end(); ptr++)
		this->v.push_back(*ptr);
}
