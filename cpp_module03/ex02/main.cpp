#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap trap1("Goku");
    ScavTrap trap2("Vegeta");
    FragTrap trap3("Freeza");
    FragTrap trap4(trap3);

    trap1.attack("Freeza");
    trap2.guardGate();
    trap3.highFivesGuys();
    trap4.highFivesGuys();

	return (0);
}
