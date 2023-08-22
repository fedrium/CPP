#include "HumanA.hpp"

void    HumanA::attack()
{
    std:: cout << name << " attacks with their "<< weapon.getType() << std:: endl;
}

HumanA::HumanA(std::string name, Weapon &wep) : weapon(wep)
{
    this->name.assign(name);
}
