
#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &data)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = data;
}

Dog &Dog::operator=(const Dog &data)
{
    std::cout << "Dog copy assigment operator called" << std::endl;
    this->type = data.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << type << " say Hauuww" << std::endl;
}