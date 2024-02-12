
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	name = "Deniz";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str)
{
	name = str;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &data)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = data;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &data)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->name = data.name;
	this->hitPoints = data.hitPoints;
	this->energyPoints = data.energyPoints;
	this->attackDamage = data.attackDamage;

	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if(hitPoints <= 0 || energyPoints <= 0)
	{	
		std::cout << "I cannot do anything for attack" << std::endl;
		return ;
	}
		std::cout << "ClapTrap " << name << "attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "I cannot do anything" << std::endl;
		return ;
	}
		std::cout << "ClapTrap " << name << "take damage " << amount << std::endl;
		attackDamage += amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "I cannot do anything cause i don't have a energy" << std::endl;
		return ;
	}
		std::cout << "ClapTrap " << name << "be repaired " << amount << std::endl;
		hitPoints += amount;
		energyPoints -= 1;
}
