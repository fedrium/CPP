#include "Harl.hpp"

int main(int argc, char **argv)
{
	std::string level;
	Harl harl;

	if (argc != 2)
	{
		std::cout << "One parameter please." << std::endl;
		exit (2);
	}
	level = argv[1];
	harl.complain(level);
}