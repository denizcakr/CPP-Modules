
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::HumanB(std::string name, Weapon *weapon)
{
    this->name = name;
    this->weapon = weapon;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with his: " << this->weapon->getType() << std::endl;
}