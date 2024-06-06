#include "MStack.hpp"

int main()
{
    MutantStack<int> mutantstack;

    mutantstack.push(1);
    mutantstack.push(2);
    mutantstack.pop();
    mutantstack.push(3);

    MutantStack<int>::iterator start = mutantstack.begin();
    MutantStack<int>::iterator end = mutantstack.end();

    while (start < end)
    {
        std::cout << *start << std::endl;
        start++;
    }

    std::stack<int> s(mutantstack);

	MutantStack<int>	s2(mutantstack);

	for (MutantStack<int>::iterator i = s2.begin(); i != s2.end(); i++)
		std::cout << *i << std::endl;
	for (MutantStack<int>::iterator i = s2.begin(); i != s2.end(); i++)
		*i = 1;
	for (MutantStack<int>::iterator i = s2.begin(); i != s2.end(); i++)
		std::cout << *i << std::endl;

	return 0;
}
