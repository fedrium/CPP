#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>
#include <string>

class Zombie
{
	private:
		std:: string name;
	public:
		void	announce( void );
		Zombie(std:: string zname);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif