#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(const std::string& n);
		ScavTrap(const ScavTrap& original);
		ScavTrap& operator=(const ScavTrap& original);
		~ScavTrap();

		void guardGate();
		void attack(const std::string& target);
};

#endif