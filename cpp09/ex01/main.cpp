#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid argument" << endl;
		return (1);
	}

	RPN rpn;

	if (rpn.split(argv[1]) == 1)
		return (1);
	std::cout << rpn.getValue() << endl;
	return (0);
}