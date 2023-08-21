#include "Zombie.hpp"

void    Zombie::announce( void )
{
    cout << name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
};

Zombie::Zombie(std:: string zname)
{
    name = zname;
};

Zombie::~Zombie()
{
    cout << name << " is ded" << std::endl;
};