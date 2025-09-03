#include <iostream>

class ClapTrap {
	private:
		std::string name;
		int hit_pts;
		int energy_pts;
		int atk_dmg;
	public:
		ClapTrap(const std::string& n);
		ClapTrap(const ClapTrap& original);
		ClapTrap& operator=(const ClapTrap& original);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
