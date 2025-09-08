#include "ScavTrap.hpp"

int main()
{
	ClapTrap trap1("Goku");
	ScavTrap trap2("Freeza");
	ScavTrap trap3(trap2);

	trap2 = ScavTrap("Vegeta");

	trap1.attack("Freeza");
	trap2.attack("Goku");
	trap3.attack("Goku");
	trap2.guardGate();

	return (0);
}
