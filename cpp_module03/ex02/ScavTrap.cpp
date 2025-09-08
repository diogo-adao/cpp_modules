#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& n): ClapTrap(n)
{
	std::cout << "Scav constructor called" << std::endl;
	hit_pts = 100;
	energy_pts = 50;
	atk_dmg = 20;
	max_hp = 100;
}

ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original)
{
	std::cout << "Scav copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& original)
{
	ClapTrap::operator=(original);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_pts > 0 && energy_pts > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << atk_dmg << " points of damage!" << std::endl;
		energy_pts--;
	}
	else
		std::cout << "ScavTrap " << name << " is tired or dead" << std::endl;

	// Debug
/* 	std::cout << name << " Health: " << hit_pts << std::endl;
	std::cout << name << " Energy: " << energy_pts << std::endl; */
}
