#include "PmergeMe.hpp"
#include <sys/time.h>

int numberCheck(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	string temp;
	PmergeMe pm;
	std::vector<int> num_holder;

	if (argc == 1)
	{
		std::cerr << "Error!" << endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		temp = argv[i];
		if (numberCheck(temp) == 0)
			num_holder.push_back(atoi(argv[i]));
		else
		{
			std::cerr << "Error!" << endl;
			return (1);
		}
	}

	int now = -1;
	std::vector<int>::iterator one;
	for (one = num_holder.begin(); one < num_holder.end(); one++)
	{
		now = *one;
		for (std::vector<int>::iterator two = one + 1; two < num_holder.end(); two++)
		{
			if (now == *two)
			{
				std::cerr << "Error!" << endl;
				return (1);
			}
		}
	}

	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long sec = tv.tv_sec;
	unsigned long micro = tv.tv_usec;
	pm.insert_value(num_holder);
	cout << "After: ";
	pm.printVec();
	cout << endl;
	gettimeofday(&tv, NULL);
	float sec2 = tv.tv_sec;
	float micro2 = tv.tv_usec;
	float time = float(sec2 - sec) + (float)((micro2 - micro) / 10000);
	cout << "Time to process a range of " << argc - 1 <<  " elements with std::vector : " << time << " us";

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec;
	micro = tv.tv_usec;
	pm.insert_value_l(num_holder);
	gettimeofday(&tv, NULL);
	sec2 = tv.tv_sec;
	micro2 = tv.tv_usec;
	time = float(sec2 - sec) + (float)((micro2 - micro) / 10000);
	cout << "Time to process a range of " << argc - 1 <<  " elements with std::list : " << time << " us" << endl;
}

// vec is faster than list in a long list of number is because vector can randomly access numbers since its in an array but list cant because its in a doubly linked list
