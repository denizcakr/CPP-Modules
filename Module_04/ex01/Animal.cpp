
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &data)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = data;
}

Animal &Animal::operator=(const Animal &data)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = data.type;
	return *this;
}

void  Animal::makeSound() const
{
	std::cout << "Animal cannot say anything" << std::endl;
}

const std::string Animal::getType() const
{
	return type;
}
