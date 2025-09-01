#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(const std::string& n);
		void setWeapon(Weapon &w);
		void attack();
};
