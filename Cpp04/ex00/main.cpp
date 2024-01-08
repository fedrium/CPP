#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound(); //will output the cat sound!
	i->makeSound();
	meta->makeSound();

	// const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	delete(meta);
	delete(i);
	delete(j);
	delete(k);
	return (0);
}
