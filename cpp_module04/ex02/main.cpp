#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "========== POLYMORPHIC TEST ==========" << std::endl;
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	delete dog;
	delete cat;

	std::cout << "\n========== ARRAY TEST ==========" << std::endl;
	const int SIZE = 4;
	Animal* animals[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{
		if (i < SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < SIZE; ++i)
	{
		animals[i]->makeSound();
		std::cout << "Type: " << animals[i]->getType() << std::endl;
	}

	for (int i = 0; i < SIZE; ++i)
		delete animals[i];

	std::cout << "\n========== DEEP COPY TEST ==========" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "Eat");

	Dog* dog2 = new Dog(*dog1);
	dog1->getBrain()->setIdea(0, "Sleep");

	std::cout << "Original Dog idea: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea: " << dog2->getBrain()->getIdea(0) << std::endl;

	Cat* cat1 = new Cat();
	cat1->getBrain()->setIdea(0, "Nap");

	Cat* cat2 = new Cat(*cat1);
	cat1->getBrain()->setIdea(0, "Play");

	std::cout << "Original Cat idea: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Cat idea: " << cat2->getBrain()->getIdea(0) << std::endl;

	delete dog1;
	delete dog2;
	delete cat1;
	delete cat2;

	return 0;
}
