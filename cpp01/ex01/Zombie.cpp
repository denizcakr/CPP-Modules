
#include "Zombie.hpp"

Zombie::Zombie(std::string Name) {
    name = Name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name){
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}