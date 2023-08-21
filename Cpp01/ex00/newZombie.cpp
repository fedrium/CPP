#include "Zombie.hpp"

Zombie* newZombie(std:: string name)
{
	Zombie *zom;

	cout << name;
	zom = new Zombie(name);
	return zom;
};