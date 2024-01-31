
#include "Zombie.hpp"

Zombie::Zombie()
{

}

void Zombie::setName(std::string newName)
{
    name = newName;
}

Zombie::Zombie(std::string Name) {
    name = Name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name){
    return new Zombie(name);
}

Zombie::~Zombie() {}