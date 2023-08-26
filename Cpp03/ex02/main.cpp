#include "FragTrap.hpp"

int main()
{
    FragTrap A("William");
    FragTrap B(A);
    FragTrap C;

    C = A;
    A.attack("Wallace");
    A.takeDamage(3);
    A.beRepaired(1);
    A.highFivesGuys();
    B.attack("Edison");
    B.takeDamage(3);
    B.beRepaired(1);
    C.attack("Qua");
    C.takeDamage(3);
    C.beRepaired(1);
}