
#include "Weapon.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string Type)
{
    type = Type;
}

void Weapon::setType(std::string Type)
{
    type = Type;
}

const std::string &Weapon::getType() const
{
    return (type);
}
