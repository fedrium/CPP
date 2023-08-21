#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std:: cout << name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
};

Zombie::Zombie(std:: string zname)
{
    zname = name;
};

Zombie::~Zombie()
{
    std:: cout << name << "is ded" << std::endl;
};