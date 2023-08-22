#include "Weapon.hpp"

#include <string>

std::string Weapon::getType()
{
    return(type);
}

void    Weapon::setType(std::string ntype)
{
    type = ntype;
}

Weapon::Weapon(std::string ntype)
{
    type = ntype;
}

Weapon::Weapon()
{
    
}