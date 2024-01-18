#include "iter.hpp"

int main()
{
	int a[] = {0, 1, 2, 3, 4};

	::iter(a, 5, plusOne);
	for (int i = 0; i < 5; i++)
	{
		std::cout << a[i] << std::endl;
	}
}