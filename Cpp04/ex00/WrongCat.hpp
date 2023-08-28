#ifndef WrongCat_HPP
#define WrongCat_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &c);
		WrongCat &operator=(const WrongCat &c);
		~WrongCat();
		void	makeSound() const;
};

#endif