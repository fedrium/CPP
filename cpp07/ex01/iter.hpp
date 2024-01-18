#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <functional>

void	plusOne(int &i)
{
	i++;
}

template <typename arrayT, typename funcT> void iter (arrayT *a, int n, funcT func)
{
	for (int i = 0; i < n; i++)
	{
		func(a[i]);
	}
}

#endif 