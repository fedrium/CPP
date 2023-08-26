#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
    this->Name = Name;
    this->HP = 100;
    this->EP = 50;
    this->atk = 20;
}

ScavTrap::ScavTrap()
{

}

ScavTrap::ScavTrap(const ScavTrap &c) : ClapTrap(c)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
    // *this = c;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this == &copy)
        return (*this);
    this->Name = copy.Name;
    this->HP = copy.HP;
    this->EP = copy.EP;
    this->atk = copy.atk;
    return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (EP > 0)
    {
        this->EP = this->EP - 1;
        std::cout << "ScavTrap " << this->Name <<  " attacks " << target << ", causing " << this->atk << " points of damage!" << std::endl;
    }
    else
        std::cout << "Not enough Energy Points" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate Keeper Mode";
}