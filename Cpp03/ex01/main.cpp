#include "ScavTrap.hpp"

int main()
{
    ScavTrap A("William");
    ScavTrap B("Wallace");
    ScavTrap C("Edison");

    A.attack("Wallace");
    B.takeDamage(20);
    B.beRepaired(1);
    A.guardGate();
    B.attack("Edison");
    C.takeDamage(20);
    C.beRepaired(1);
    B.attack("William");
    A.takeDamage(20);
    A.beRepaired(1);
}