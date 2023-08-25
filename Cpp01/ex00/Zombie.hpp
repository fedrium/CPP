#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>
#include <string>

using std::cout;

class Zombie
{
	private:
		std::string name;
	public:
		void	announce( void );
		Zombie(std::string zname);
		~Zombie();
};

Zombie* newZombie(std::string name);

void 	randomChump(std::string name);

#endif