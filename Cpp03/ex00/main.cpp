#include "ClapTrap.hpp"

int main()
{
    ClapTrap A("William");
    ClapTrap B(A);
    ClapTrap C;

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