#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	int hasDot = 0;

	for (int i = 0; i < (int)str.size();)
	{
		if (str[i] == '.')
		{
			hasDot++;
			i++;
		}
		if (i + 1 == (int)str.size() && str[i] == 'f')
			std::cout << "its a float\n";
		if (!isdigit(str[i]))
			break;
		if (hasDot > 1)
			break;
		if (i + 1 == (int)str.size() && hasDot == 1)
		{
			std::cout << "its a double\n";
			double tmp = (double)str;
		}
		if (i + 1 == (int)str.size() && hasDot == 0)
			std::cout << "its a int\n";
		i++;
	}
	if (isalpha(str[0]) && str.size() == 1)
	{
		std::cout << "its a char\n";
	}
}