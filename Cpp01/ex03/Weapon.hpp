#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string type;
    public:
        std::string getType();
        void        setType(std::string wname);
        Weapon(std::string ntype);
        Weapon();
};

#endif