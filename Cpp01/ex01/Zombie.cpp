#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std:: cout << name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
};

Zombie::Zombie(std:: string zname)
{
    name = zname;
};

Zombie::~Zombie()
{
    std:: cout << name << "is ded" << std::endl;
};