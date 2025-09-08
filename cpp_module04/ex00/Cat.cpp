#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "[CAT] Default Constructor Called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& src): Animal(src)
{
	std::cout << "[CAT] Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	Animal::operator=(src);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[CAT] Destructor Called" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "*miau* *miau*" << std::endl;
}
