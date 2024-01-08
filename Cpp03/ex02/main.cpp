#include "FragTrap.hpp"

int main()
{
    FragTrap A("William");
    FragTrap B("Wallace");
    FragTrap C("Edison");

    A.attack("Wallace");
    B.takeDamage(20);
    B.beRepaired(1);
    A.highFivesGuys();
    B.attack("Edison");
    C.takeDamage(20);
    C.beRepaired(1);
    B.attack("William");
    A.takeDamage(20);
    A.beRepaired(1);
}