#include "Zombie.hpp"

int main(int argc, char **argv)
{
	int zomNum;
	std::string name;
	
	if (argc == 1)
	{
		zomNum = 5;
		name = "amogus";
	}
	else
	{
		zomNum = atoi(argv[1]);
		name = argv[2];
	}
	Zombie *zom = zombieHorde(zomNum, name);
	for (int i = 0; i < zomNum; i++)
	{
		zom[i].announce();
	}
	return 0;
}