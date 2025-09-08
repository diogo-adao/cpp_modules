#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& n): ClapTrap(n)
{
	std::cout << "Frag constructor called" << std::endl;
	hit_pts = 100;
	energy_pts = 100;
	atk_dmg = 30;
	max_hp = 100;
}

FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original)
{
	std::cout << "Frag copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& original)
{
	ClapTrap::operator=(original);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Frag destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a positive high-five! ✋" << std::endl;
}
