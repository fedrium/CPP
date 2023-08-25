#include "ClapTrap.hpp"

int main()
{
    ClapTrap CT("William");

    CT.attack("Wallace");
    CT.takeDamage(3);
    CT.beRepaired(1);
}