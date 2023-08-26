#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string Name;
        int         HP;
        int         EP;
        int         atk;
    public:
        ClapTrap(std::string Name);
        ClapTrap();
        ClapTrap(const ClapTrap &c);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif