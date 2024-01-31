
#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string newName, Weapon &newWeapon) : weapon(newWeapon)
{
    name = newName;
}

void HumanA::attack()
{
    std::cout << name << " attacks with his: " << weapon.getType() << std::endl;
}