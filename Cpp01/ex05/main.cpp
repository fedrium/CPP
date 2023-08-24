#include "Harl.hpp"

int main(int argc, char **argv)
{
	std::string level;
	Harl harl;

	level = argv[1];
	if (argc != 2)
		std::cout << "One parameter please.";
	harl.complain(level);
}