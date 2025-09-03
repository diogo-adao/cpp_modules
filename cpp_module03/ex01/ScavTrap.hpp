#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		std::string name;
	public:
		ScavTrap(const std::string& n);
		ScavTrap(const ScavTrap& original);
		ScavTrap& operator=(const ScavTrap& original);
		~ScavTrap();

		void guardGate();
};
