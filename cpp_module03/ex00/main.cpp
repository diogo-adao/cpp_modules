#include "ClapTrap.hpp"

int main()
{
	ClapTrap trap1("Goku");
	ClapTrap trap2("Freeza");
	ClapTrap trap3(trap2);

	trap2 = ClapTrap("Vegeta");

	trap1.attack("Freeza");
	trap3.takeDamage(5);
	trap2.attack("Freeza");
	trap3.takeDamage(3);
	trap3.beRepaired(2);
	trap3.attack("Goku");
	trap3.attack("Vegeta");
	trap1.takeDamage(5);
	trap2.takeDamage(10);
	trap2.attack("Freeza");

	return (0);
}
