#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "[DOG] Default Constructor Called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& src): Animal(src)
{
	std::cout << "[DOG] Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	Animal::operator=(src);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[DOG] Destructor Called" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "*au* *au*" << std::endl;
}
