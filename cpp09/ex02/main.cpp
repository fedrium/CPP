#include "PmergeMe.hpp"

int numberCheck(string str)
{
	for (int i = 0; i < (int)str.size() - 1; i++)
	{
		if (!isdigit(str[i]))
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
		std::cerr << "Error!" << endl;
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

	pm.insert_value(num_holder);
	pm.insert_value_l(num_holder);
	cout << "After: ";
	pm.printVec();
	cout << endl;
}