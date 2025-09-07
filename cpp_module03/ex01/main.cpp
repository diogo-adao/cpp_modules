#include "ScavTrap.hpp"

int main()
{
	ClapTrap trap1("Goku");
	ScavTrap trap2("Freeza");

    trap1.attack("Freeza");
    trap2.takeDamage(20);
    trap2.attack("Goku");
    trap2.beRepaired(10);
    trap2.attack("Goku");
    trap2.guardGate();

	return (0);
}
