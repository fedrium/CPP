#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->Name = Name;
	this->HP = 100;
	this->EP = 100;
	this->atk = 30;
}

FragTrap::FragTrap()
{

}

FragTrap::FragTrap(const FragTrap &c) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
    *this = c;
}

FragTrap &FragTrap::operator=(const FragTrap &c)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this == &c)
        return (*this);
    this->Name = c.Name;
    this->HP = c.HP;
    this->EP = c.EP;
    this->atk = c.atk;
    return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (EP > 0)
    {
        this->EP = this->EP - 1;
        std::cout << "FragTrap " << this->Name << " has damaged " << target << " for " << this->atk << " point of damage" << std::endl;
    }
    else
        std::cout << "Not enough Energy Points" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Requesting High 5" << std::endl;
}