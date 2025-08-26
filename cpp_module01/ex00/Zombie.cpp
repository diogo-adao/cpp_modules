#include "Zombie.hpp"

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string n) {
    name = n;
    std::cout << name << " was created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " was destroyed" << std::endl;
}
