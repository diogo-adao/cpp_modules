#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "[DOG] Default Constructor Called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& src): Animal(src)
{
	std::cout << "[DOG] Copy Constructor Called" << std::endl;
	brain = new Brain(*src.brain);
}

Dog& Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete brain;
		brain = new Brain(*src.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[DOG] Destructor Called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "*au* *au*" << std::endl;
}

Brain* Dog::getBrain() const { return brain; }
