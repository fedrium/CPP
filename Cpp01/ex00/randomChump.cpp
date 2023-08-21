#include "Zombie.hpp"

void 	randomChump(std:: string name)
{
    Zombie zom(name);
    cout << name;
    zom.announce();
};