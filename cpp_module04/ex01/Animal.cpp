#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[ANIMAL] Default Constructor Called" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal& original)
{
	std::cout << "[ANIMAL] Copy Constructor Called" << std::endl;
	*this = original;
}

Animal& Animal::operator=(const Animal& original)
{
	std::cout << "[ANIMAL] Copy Assignment Operator Called" << std::endl;
	if (this != &original)
		type = original.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[ANIMAL] Destructor Called" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}
