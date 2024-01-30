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

int jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void swap(std::pair<int, int> &pair)
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
		middle_ptr++;
	std::vector<std::pair<int, int> > front(pair_vec.begin(), middle_ptr);
	std::vector<std::pair<int, int> > back(middle_ptr, pair_vec.end());

	//recurse
	big_sort(front);
	big_sort(back);

	pair_vec.clear();
	//insert the values
	vec_insert(front, back, pair_vec);
}

static std::vector<int> VecFJSort(std::vector<std::pair<int, int> > &vec_pair, int is_odd, int leftover)
{
	std::vector<int> big;
	std::vector<int> small;

	std::vector<std::pair<int, int> >::iterator vec_pair_ptr;
	std::vector<int>::iterator big_ptr;
	std::vector<int>::iterator small_ptr;

	for (vec_pair_ptr = vec_pair.begin(); vec_pair_ptr < vec_pair.end(); vec_pair_ptr++)
	{
		small.push_back((*vec_pair_ptr).first);
		big.push_back((*vec_pair_ptr).second);
	}

	//insert first in small into big cuz its always smaller
	big.insert(big.begin(), small.front());
	small.erase(small.begin());

	int n = 0;
	int jacob = 0;
	int i = 2;

	std::vector<int>::iterator pend = small.begin();
	while (n < (int)small.size())
	{
		small_ptr = small.begin();
		jacob = jacobsthal(i);
		if (jacob >= (int)small.size())
			break;
		std::advance(small_ptr, jacob - 1);
		small.insert(pend, *small_ptr);
		small.erase(small_ptr + 1);
		++pend;
		++i;
		n++;
	}

	for (small_ptr = small.begin(); small_ptr < small.end(); small_ptr++)
	{
		big.insert(std::lower_bound(big.begin(), big.end(), *small_ptr), *small_ptr);
	}
	if (is_odd == 1)
	{
		big.insert(std::lower_bound(big.begin(), big.end(), leftover), leftover);
	}

	return(big);
}

void PmergeMe::Sort(std::vector<int> vec)
{
	std::vector<std::pair<int, int> > pair_vec;
	std::vector<std::pair<int, int> >::iterator pair_vec_ptr;
	std::vector<int>::iterator ptr;
	std::pair<int, int> temp;

	int is_odd = 0;
	int leftover;
	
	//find if the vector has a leftover
	if (vec.size() < 2)
		return;
	if (vec.size() % 2 == 1)
	{
		is_odd = 1;
		leftover = *(vec.end() - 1);
		vec.pop_back();
	}

	//make pair
	for (ptr = vec.begin(); ptr < vec.end(); ptr += 2)
	{
		temp = std::make_pair(*ptr, *(ptr + 1));
		if (temp.first > temp.second)
			swap(temp);
		pair_vec.push_back(temp);
	}

	big_sort(pair_vec);

	this->v = VecFJSort(pair_vec, is_odd, leftover);

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
	cout << "Before: ";
	this->printVec();
	cout << endl;
	Sort(this->v);
}

/*-------------------------------List------------------------------------*/

static void list_insert(std::list<std::pair<int, int> > &front, std::list<std::pair<int, int> > &back, std::list<std::pair<int, int> > &pair_list)
{
	std::list<std::pair<int, int> >::iterator front_itr = front.begin();
	std::list<std::pair<int, int> >::iterator back_itr = back.begin();

	//push the value into vector if its smaller
	while (front_itr != front.end() && back_itr != back.end())
	{
		if ((*front_itr).second < (*back_itr).second)
		{
			pair_list.push_back(*front_itr);
			front_itr++;
		}
		if ((*back_itr).second < (*front_itr).second)
		{
			pair_list.push_back(*back_itr);
			back_itr++;
		}
	}

	//leftover
	while (front_itr != front.end())
	{
		pair_list.push_back(*front_itr);
		front_itr++;
	}
	while (back_itr != back.end())
	{
		pair_list.push_back(*back_itr);
		back_itr++;
	}
}

static void big_sort_l(std::list<std::pair<int, int> > &pair_list)
{
	if (pair_list.size() < 2)
		return;
	
	std::list<std::pair<int, int> > middle;
	std::list<std::pair<int, int> >::iterator middle_ptr = pair_list.begin();
	std::advance(middle_ptr, pair_list.size() / 2);
	std::list<std::pair<int, int> > front(pair_list.begin(), middle_ptr);
	std::list<std::pair<int, int> > back(middle_ptr, pair_list.end());

	big_sort_l(front);
	big_sort_l(back);

	pair_list.clear();
	list_insert(front, back, pair_list);
}

void PmergeMe::insert_value_l(std::vector<int> vec)
{
	std::vector<int>::iterator ptr = vec.begin();

	for (; ptr != vec.end(); ptr++)
		this->l.push_back(*ptr);
	this->Sort(this->l);
}

static std::list<int> ListFJSort(std::list<std::pair<int, int> > &pair_list, int is_odd, int leftover)
{
	std::list<int> big;
	std::list<int> small;

	std::list<std::pair<int, int> >::iterator list_pair_ptr;
	std::list<int>::iterator big_ptr;
	std::list<int>::iterator small_ptr;

	for (list_pair_ptr = pair_list.begin(); list_pair_ptr != pair_list.end(); ++list_pair_ptr)
	{
		small.push_back((*list_pair_ptr).first);
		big.push_back((*list_pair_ptr).second);
	}

	big.insert(big.begin(), small.front());
	small.erase(small.begin());

	int n = 0;
	int jacob = 0;
	int i = 2;

	// for (small_ptr = small.begin(); small_ptr != small.end(); ++small_ptr)
	// {
	// 	cout << *small_ptr << " ";
	// }
	// cout << endl;
	// for (big_ptr = big.begin(); big_ptr != big.end(); ++big_ptr)
	// {
	// 	cout << *big_ptr << " ";
	// }
	// cout << endl;

	std::list<int>::iterator tmp;

	std::list<int>::iterator pend = small.begin();
	while (n < (int)small.size())
	{
		small_ptr = small.begin();
		jacob = jacobsthal(i);
		if (jacob >= (int)small.size())
			break;
		std::advance(small_ptr, jacob - 1);
		small.insert(pend, *small_ptr);
		small_ptr = small.begin();
		std::advance(small_ptr, n);
		small.erase(small_ptr);
		++pend;
		++i;
		n++;
	}

	int now;
	for (small_ptr = small.begin(); small_ptr != small.end(); ++small_ptr)
	{
		now = *small_ptr;
		if (now < *small_ptr)

		cout << *small_ptr << " ";
	}
	cout << endl;
	// for (big_ptr = big.begin(); big_ptr != big.end(); ++big_ptr)
	// {
	// 	cout << *big_ptr << " ";
	// }
	// cout << endl;

	for (small_ptr = small.begin(); small_ptr != small.end(); ++small_ptr)
	{
		big.insert(std::lower_bound(big.begin(), big.end(), *small_ptr), *small_ptr);
	}
	if (is_odd == 1)
	{
		big.insert(std::lower_bound(big.begin(), big.end(), leftover), leftover);
	}
	return (big);
}

void PmergeMe::Sort(std::list<int> list)
{
	std::list<std::pair<int, int> > pair_list;
	std::list<std::pair<int, int> >::iterator pair_list_ptr;
	std::pair<int, int> temp;
	std::list<int>::iterator ptr;

	int is_odd = 0;
	int leftover;
	
	if (list.size() < 2)
		return;
	if (list.size() % 2 == 1)
	{
		is_odd = 1;
		leftover = *(--list.end());
		list.pop_back();
	}

	// for (ptr2 = list.begin(); ptr2 != list.end(); ++ptr2)
	// {
	// 	cout << "num " << *ptr2 << endl;
	// }

	//make pair
	std::list<int>::iterator ptr2;
	for (ptr = list.begin(); ptr != list.end(); std::advance(ptr, 2))
	{
		ptr2 = ptr;
		std::advance(ptr2, 1);
		temp = std::make_pair(*ptr, *ptr2);
		// cout << "num : " << temp.first << " " << temp.second << endl;
		if (temp.first > temp.second)
			swap(temp);
		pair_list.push_back(temp);
	}

	big_sort_l(pair_list);

	this->l = ListFJSort(pair_list, is_odd, leftover);

	// for (pair_list_ptr = pair_list.begin(); pair_list_ptr != pair_list.end(); ++pair_list_ptr)
	// {
	// 	cout << "num : " << (*pair_list_ptr). first << " " << (*pair_list_ptr).second << endl;
	// }

	// cout << "list num: ";
	// std::list<int>::iterator itr;
	// for (itr = l.begin(); itr != l.end(); ++itr)
	// {
	// 	cout << *itr << " ";
	// }
	// cout << endl;
}

void PmergeMe::printVec()
{
	std::vector<int>::iterator ptr;

	for(ptr = this->v.begin(); ptr < this->v.end(); ptr++)
	{
		cout << *ptr << " ";
	}
}