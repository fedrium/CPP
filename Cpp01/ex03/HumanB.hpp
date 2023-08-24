#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
    public:
        void attack();
        HumanB(std::string name);
        // HumanB(std::string name, Weapon &wep);
        void    setWeapon(Weapon &BWeapon);
    private:
        std::string name;
        Weapon *weapon;
};

#endif