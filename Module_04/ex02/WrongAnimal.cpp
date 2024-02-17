
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &data)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = data;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &data)
{
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
	this->type = data.type;
	return *this;
}

void  WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal say mooo" << std::endl;
}

const std::string WrongAnimal::getType() const
{
	return type;
}
