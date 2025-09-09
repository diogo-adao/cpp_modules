#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "[WRONG CAT] Default Constructor Called" << std::endl;
	type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src)
{
	std::cout << "[WRONG CAT] Copy Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	WrongAnimal::operator=(src);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WRONG CAT] Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "*miau* *miau*" << std::endl;
}
