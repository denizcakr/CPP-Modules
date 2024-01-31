
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string Name)
{
    name = Name;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    weapon = &Weapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with his: " << weapon->getType() << std::endl;
}