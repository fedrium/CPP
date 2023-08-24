#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	void	(Harl::*harl[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	if (level.compare("DEBUG") == 0)
		(this->*harl[0])();
	if (level.compare("INFO") == 0)
		(this->*harl[1])();
	if (level.compare("WARNING") == 0)
		(this->*harl[2])();
	if (level.compare("ERROR") == 0)
		(this->*harl[3])();
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}