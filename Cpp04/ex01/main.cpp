#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// delete j;//should not create a leak
	// delete i;

	// return 0;
	Dog dog;
	Cat cat;
	std::cout << dog.getIdea(0);
	std::cout << cat.getIdea(0);

	cat.setIdea(0, "FISH");
	dog.setIdea(0, "BONE");
	std::cout << "cat thinking : " << cat.getIdea(0) << std::endl;
	std::cout << "dog thinking : " << dog.getIdea(0) << std::endl;
	Cat cat2(cat);
	Dog dog2(dog);
	std::cout << "cat thinking : " << cat.getIdea(0) << std::endl;
	std::cout << "dog thinking : " << dog.getIdea(0) << std::endl;
	std::cout << "cat2 thinking : " << cat2.getIdea(0) << std::endl;
	std::cout << "dog2 thinking : " << dog2.getIdea(0) << std::endl;
	cat2.setIdea(0, "SLEEP");
	dog2.setIdea(0, "WALK");
	std::cout << "cat thinking : " << cat.getIdea(0) << std::endl;
	std::cout << "dog thinking : " << dog.getIdea(0) << std::endl;
	std::cout << "cat2 thinking : " << cat2.getIdea(0) << std::endl;
	std::cout << "dog2 thinking : " << dog2.getIdea(0) << std::endl;

	
	return (0);
}