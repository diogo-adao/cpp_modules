#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "========== SUBJECT TEST ==========" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;

	std::cout << "\n========== TEST 1 ==========" << std::endl;
	const int SIZE = 4;
	Animal* animals[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		if (i < SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	animals[0]->makeSound();
	std::cout << "animal type: " << animals[0]->getType() << std::endl;
	animals[2]->makeSound();
	std::cout << "animal type: " << animals[2]->getType() << std::endl;

	for (int i = 0; i < SIZE; ++i)
		delete animals[i];

	std::cout << "\n========== TEST 2 ==========" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "Eat");
	Dog* dog2 = new Dog(*dog1);
	dog1->getBrain()->setIdea(0, "Sleep");
	std::cout << dog2->getBrain()->getIdea(0) << std::endl;

	delete dog1;
	delete dog2;

	std::cout << "\n========== TEST 3 ==========" << std::endl;
	Cat* cat1 = new Cat();
	cat1->getBrain()->setIdea(0, "Nap");
	Cat* cat2 = new Cat(*cat1);
	cat1->getBrain()->setIdea(0, "Play");
	std::cout << cat2->getBrain()->getIdea(0) << std::endl;

	delete cat1;
	delete cat2;

	return (0);
}
