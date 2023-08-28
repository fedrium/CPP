#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &c);
		WrongAnimal &operator=(const WrongAnimal &c);
		virtual ~WrongAnimal();
		virtual void	makeSound() const;
		std::string	getType() const;
};

#endif