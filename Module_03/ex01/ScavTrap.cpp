
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    name = "Default";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string str)
{
    std::cout << "ScavTrap string constructor called" << std::endl;
    name = str;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &data)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;

    *this = data;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &data)
{
    std::cout << "ScavTrap copy assigment operator called" << std::endl;
    this->name = data.name;
	this->hitPoints = data.hitPoints;
	this->energyPoints = data.energyPoints;
	this->attackDamage = data.attackDamage;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}