#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &c);
		Cat &operator=(const Cat &c);
		~Cat();
		void	makeSound() const;
		std::string getIdea(int i) const;
		void	setIdea(int i, std::string input);
	private:
		Brain *brain;
};

#endif