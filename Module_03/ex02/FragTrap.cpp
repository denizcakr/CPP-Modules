
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    name = "Deniz";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string str)
{
    std::cout << "FragTrap string constructor called" << std::endl;
    name = str;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &data)
{
    std::cout << "FragTrap copy constructor called" << std::endl;

    *this = data;
}

FragTrap &FragTrap::operator=(const FragTrap &data)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    this->name = data.name;
	this->hitPoints = data.hitPoints;
	this->energyPoints = data.energyPoints;
	this->attackDamage = data.attackDamage;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High five!" << std::endl;
}
