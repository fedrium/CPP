#include "ScavTrap.hpp"

int main()
{
    ScavTrap A("William");
    ScavTrap B(A);
    ScavTrap C;

    C = A;
    A.attack("Wallace");
    A.takeDamage(3);
    A.beRepaired(1);
    B.attack("Edison");
    B.takeDamage(3);
    B.beRepaired(1);
    C.attack("Qua");
    C.takeDamage(3);
    C.beRepaired(1);
}