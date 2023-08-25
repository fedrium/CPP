#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std:: cout << name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
};

Zombie::Zombie()
{

};

Zombie::~Zombie()
{
    std:: cout << name << "is ded" << std::endl;
};

std::string    Zombie::get()
{
    return (name);
};

void    Zombie::set(std::string zname)
{
    name = zname;
};