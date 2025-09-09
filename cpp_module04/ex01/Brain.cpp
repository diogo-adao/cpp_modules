#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[BRAIN] Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "[BRAIN] Copy Constructor Called" << std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "[BRAIN] Copy Assignment Operator Called" << std::endl;
	if (this != &src)
		*this = src;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[BRAIN] Destructor Called" << std::endl;
}
