#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap trap1("Goku");
	ScavTrap trap2("Vegeta");
	FragTrap trap3("Freeza");
	FragTrap trap4(trap3);

	trap3 = FragTrap("Cell");

	trap1.attack("Freeza");
	trap2.attack("Freeza");
	trap3.attack("Goku");
	trap4.attack("Vegeta");
	trap3.highFivesGuys();
	trap4.highFivesGuys();

	return (0);
}
