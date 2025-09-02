#include "ClapTrap.hpp"

int main()
{
	ClapTrap trap1("Goku");
	ClapTrap trap2("Freeza");

	trap1.attack("Freeza");
	trap2.takeDamage(5);
	trap2.attack("Goku");
	trap1.takeDamage(3);
	trap1.beRepaired(2);
	trap2.beRepaired(3);
	trap1.attack("Freeza");
	trap2.takeDamage(10);
	trap2.attack("Goku");

	return (0);
}
