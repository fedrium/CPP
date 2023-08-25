#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		void	announce( void );
		Zombie();
		~Zombie();
		std::string get();
		void	set(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif