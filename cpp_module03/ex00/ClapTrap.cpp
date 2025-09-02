#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& n) {
	std::cout << "Constructor called" << std::endl;
	name = n;
	hit_pts = 10;
	energy_pts = 10;
	atk_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap& original) {
	std::cout << "Copy constructor called" << std::endl;
	name = original.name;
	hit_pts = original.hit_pts;
	energy_pts = original.energy_pts;
	atk_dmg = original.atk_dmg;
}

ClapTrap ClapTrap::operator=(const ClapTrap& original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&original != this)
	{
		name = original.name;
		hit_pts = original.hit_pts;
		energy_pts = original.energy_pts;
		atk_dmg = original.atk_dmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_pts > 0 && energy_pts > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << atk_dmg << " points of damage!" << std::endl;
		energy_pts--;
	}
	else
		std::cout << "ClapTrap " << name << " is tired or dead" << std::endl;

	// Debug
	std::cout << name << " Health: " << hit_pts << std::endl;
	std::cout << name << " Energy: " << energy_pts << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_pts > 0)
	{
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage" << std::endl;
		for (unsigned int i = 0; i < amount; i++)
		{
			if (hit_pts > 0)
				hit_pts--;
			else
				break;
		}
	}
	else
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;

	// Debug
	std::cout << name << " Health: " << hit_pts << std::endl;
	std::cout << name << " Energy: " << energy_pts << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_pts > 0 && energy_pts > 0)
	{
		std::cout << "ClapTrap " << name << " repaired itself, gaining " << amount << " hit points" << std::endl;
		energy_pts--;
		for (unsigned int i = 0; i < amount; i++)
		{
			if (hit_pts < 10)
				hit_pts++;
			else
				break;
		}
	}
	else
		std::cout << "ClapTrap " << name << " is tired or dead" << std::endl;

	// Debug
	std::cout << name << " Health: " << hit_pts << std::endl;
	std::cout << name << " Energy: " << energy_pts << std::endl;
}
