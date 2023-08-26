#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string Name);
		FragTrap(const FragTrap &c);
		FragTrap &operator=(const FragTrap &c);
		~FragTrap();
		FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif