#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WRONG ANIMAL] Default Constructor Called" << std::endl;
	type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	std::cout << "[WRONG ANIMAL] Copy Constructor Called" << std::endl;
	*this = original;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
	std::cout << "[WRONG ANIMAL] Copy Assignment Operator Called" << std::endl;
	if (this != &original)
		*this = original;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WRONG ANIMAL] Destructor Called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal Sound" << std::endl;
}
