#include "Zombie.hpp"

int main() {
	Zombie *h = zombieHorde(5, "Clicker");
	Zombie *h2 = zombieHorde(5, "Runner");

	for (int i = 0; i < 5; i++) {
		h[i].announce();
		h2[i].announce();
	}
	delete[] h;
	delete[] h2;
	return (0);
}
