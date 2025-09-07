#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		int hit_pts;
		int energy_pts;
		int atk_dmg;
		int max_hp;
	public:
		ClapTrap(const std::string& n);
		ClapTrap(const ClapTrap& original);
		ClapTrap& operator=(const ClapTrap& original);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif