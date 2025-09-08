#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
/* 	std::cout << "========== SUBJECT TEST ==========" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound(); */

	std::cout << "========== TEST 1 ==========" << std::endl;
	Cat kitty;
	kitty.makeSound();
	Dog doggy;
	doggy.makeSound();
	std::cout << "kitty type: " << kitty.getType() << std::endl;
	std::cout << "doggy type: " << doggy.getType() << std::endl;

	std::cout << "========== DESTRUCTORS ==========" << std::endl;

	return (0);
}
