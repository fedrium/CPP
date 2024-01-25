#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Error" << endl;

	RPN rpn;

	rpn.split(argv[1]);
}