
#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &data)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = data;
}

Cat &Cat::operator=(const Cat &data)
{
    std::cout << "Cat copy assigment operator called" << std::endl;
    this->type = data.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << type << " say Miyuw" << std::endl;
}