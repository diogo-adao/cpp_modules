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
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[BRAIN] Destructor Called" << std::endl;
}

void Brain::setIdea(int i, const std::string& idea)
{
	if (i >= 0 && i < 100)
		ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (ideas[i]);
	return "";
}
