#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "[CAT] Default Constructor Called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& src): Animal(src)
{
	std::cout << "[CAT] Copy Constructor Called" << std::endl;
	brain = new Brain(*src.brain);
}

Cat& Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		delete brain;
		brain = new Brain(*src.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[CAT] Destructor Called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "*miau* *miau*" << std::endl;
}

Brain* Cat::getBrain() const { return brain; }
