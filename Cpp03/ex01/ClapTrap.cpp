#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
{
    std::cout << "Default constructor called" << std::endl;
    this->Name = Name;
    this->HP = 10;
    this->EP = 10;
    this->atk = 0;
}

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = c;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->Name = copy.Name;
    this->HP = copy.HP;
    this->EP = copy.EP;
    this->atk = copy.atk;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (EP > 0)
    {
        this->EP = this->EP - 1;
        std::cout << "ClapTrap " << this->Name <<  " attacks " << target << ", causing " << this->atk << " points of damage!" << std::endl;
    }
    else
        std::cout << "Not enough Energy Points" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->HP = this->HP - amount;
    if (this->HP < 0)
    {
        std::cout << "ClapTrap " << this->Name << "is dead" << std::endl;
    }
    std::cout << "ClapTrap " << this->Name << " took " << amount << " of damage" << std::endl;
    std::cout << "HP: " << this->HP << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (EP > 0)
    {
        this->EP = this->EP - 1;
        this->HP = this->HP + amount;
        std::cout << "ClapTrap " << this->Name << " healed for " << amount << " amount" << std::endl;
    }
    else
        std::cout << "Not enough Energy Points" << std::endl;
    std::cout << "HP: " << this->HP << std::endl;
}