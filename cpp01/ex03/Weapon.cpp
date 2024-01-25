
#include "Weapon.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string type)
{
    this->type = type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

std::string Weapon::getType() const
{
    return (this->type);
}