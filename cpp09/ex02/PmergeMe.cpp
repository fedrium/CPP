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

void swap(std::pair<int, int> pair)
{
	int temp = pair.first;
	pair.first = pair.second;
	pair.second = temp;
}

static void vec_insert(std::vector<std::pair<int, int> > &front, std::vector<std::pair<int, int> > &back, std::vector<std::pair<int, int> > &pair_vec)
{
	std::vector<std::pair<int, int> >::iterator front_itr = front.begin();
	std::vector<std::pair<int, int> >::iterator back_itr = back.begin();

	//push the value into vector if its smaller
	while (front_itr != front.end() && back_itr != back.end())
	{
		if ((*front_itr).second < (*back_itr).second)
		{
			pair_vec.push_back(*front_itr);
			front_itr++;
		}
		if ((*back_itr).second < (*front_itr).second)
		{
			pair_vec.push_back(*back_itr);
			back_itr++;
		}
	}

	//leftover
	while (front_itr != front.end())
	{
		pair_vec.push_back(*front_itr);
		front_itr++;
	}
	while (back_itr != back.end())
	{
		pair_vec.push_back(*back_itr);
		back_itr++;
	}
}

static void big_sort(std::vector<std::pair<int, int> > &pair_vec)
{
	if (pair_vec.size() < 2)
		return;
	
	//split the vector into 2 from the middle
	std::vector<std::pair<int, int> > middle;
	std::vector<std::pair<int, int> >::iterator middle_ptr = pair_vec.begin();
	for (int i = 0; i < (int)pair_vec.size() / 2; i++)
	{
		middle_ptr++;
		cout << "test" << endl;
	}
	std::vector<std::pair<int, int> > front(pair_vec.begin(), middle_ptr);
	std::vector<std::pair<int, int> > back(middle_ptr, pair_vec.end());

	//recurse
	big_sort(front);
	big_sort(back);

	pair_vec.clear();
	//insert the values
	vec_insert(front, back, pair_vec);
}

void PmergeMe::Sort(std::vector<int> vec)
{
	std::vector<std::pair<int, int> > pair_vec;
	std::vector<std::pair<int, int> >::iterator pair_vec_ptr;
	std::vector<int>::iterator ptr;
	std::pair<int, int> temp;

	// int is_odd = 0;
	// int odd;
	
	// if (vec.size() < 2)
	// 	return;
	// if (vec.size() % 2 == 1)
	// {
	// 	is_odd = 1;
	// 	odd = *(vec.end() - 1);
	// 	vec.pop_back();
	// }

	//make pair
	for (ptr = vec.begin(); ptr < vec.end(); ptr += 2)
	{
		temp = std::make_pair(*ptr, *(ptr + 1));
		if (temp.first > temp.second)
			swap(temp);
		pair_vec.push_back(temp);
	}

	big_sort(pair_vec);

	

	//test pair input
	// std::vector<std::pair<int, int> >::iterator ptr2;
	// for (ptr2 = pair_vec.begin(); ptr2 < pair_vec.end(); ptr2++)
	// {
	// 	cout << "num: " << (*ptr2).first << " " << (*ptr2).second << endl;
	// }
}

void PmergeMe::insert_value(std::vector<int> vec)
{
	std::vector<int>::iterator ptr = vec.begin();

	for (; ptr != vec.end(); ptr++)
		this->v.push_back(*ptr);
	Sort(this->v);
}
