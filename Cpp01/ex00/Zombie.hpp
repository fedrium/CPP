#ifndef ZOMBIE
#define ZOMBIE

#include <iostream>
#include <string>

using std::string;
using std::cout;

class Zombie
{
	private:
		string name;
	public:
		void	announce( void );
		Zombie* newZombie(string z_name){
			z_name = name;
		}
		void 	randomChump(string z_name){
			z_name = name;
		}
};

#endif