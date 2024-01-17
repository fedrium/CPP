#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (argv[1] == NULL)
		return (0);
	char *temp = argv[1];
	for (int i = 0; i < (int)sizeof(temp); i++)
	{
		if (isdigit(temp[i]) == 1 && isalpha(temp[i]) == 1 && temp[i] != '.' && temp[i] != '+' && temp[i] != '-')
		{
			std::cout << "Invalid input." << std::endl;
			return (1);
		}
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}