#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[ANIMAL] Default Constructor Called" << std::endl;
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
		*this = original;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[ANIMAL] Destructor Called" << std::endl;
}

std::string Animal::getType()
{
	return type;
}
