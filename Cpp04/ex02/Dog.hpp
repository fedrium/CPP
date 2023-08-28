#ifndef Dog_HPP
#define Dog_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &c);
		Dog &operator=(const Dog &c);
		~Dog();
		void	makeSound() const;
		std::string getIdea(int i) const;
		void	setIdea(int i, std::string input);
	private:
		Brain *brain;
};

#endif