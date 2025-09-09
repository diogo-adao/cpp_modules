#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== SUBJECT TEST ==========" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "========== WRONG TEST ==========" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound();
	wrong_meta->makeSound();

	std::cout << "========== SIMPLE TEST ==========" << std::endl;
	Animal animal;
	animal.makeSound();
	Cat kitty;
	kitty.makeSound();
	Dog doggy;
	doggy.makeSound();
	std::cout << "animal type: " << animal.getType() << std::endl;
	std::cout << "kitty type: " << kitty.getType() << std::endl;
	std::cout << "doggy type: " << doggy.getType() << std::endl;

	std::cout << "========== DESTRUCTORS ==========" << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrong_meta;
	delete wrong_i;

	return (0);
}
