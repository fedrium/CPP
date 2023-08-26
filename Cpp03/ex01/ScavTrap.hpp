#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        void guardGate();
        void attack(const std::string& target);
        ScavTrap();
        ScavTrap(std::string Name);
        ScavTrap(const ScavTrap &c);
        ScavTrap &operator=(const ScavTrap &copy);
        ~ScavTrap();
};

#endif