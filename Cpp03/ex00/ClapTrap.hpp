#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string Name;
        int         HP;
        int         EP;
        int         atk;
    public:
        ClapTrap(std::string Name);
        ClapTrap(ClapTrap &c);
        ClapTrap &operator=(ClapTrap &copy);
        ~ClapTrap();
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

// class ClapTrap
// {
// private:
//     /* data */
// public:
//     ClapTrap(/* args */);
//     ~ClapTrap();
// };

// ClapTrap::ClapTrap(/* args */)
// {
// }

// ClapTrap::~ClapTrap()
// {
// }


#endif