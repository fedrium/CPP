#include "ClapTrap.hpp"

int main()
{
    ClapTrap A("William");
    ClapTrap B("Wallace");
    ClapTrap C("Edison");

    A.attack("Wallace");
    B.takeDamage(0);
    B.beRepaired(1);
    B.attack("Edison");
    C.takeDamage(0);
    C.beRepaired(1);
    B.attack("William");
    A.takeDamage(0);
    A.beRepaired(1);
}