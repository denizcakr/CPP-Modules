
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "Wrong Cat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &data)
{
    std::cout << "Wrong Cat copy constructor called" << std::endl;
    *this = data;
}

WrongCat &WrongCat::operator=(const WrongCat &data)
{
    std::cout << "Wrong Cat copy assigment operator called" << std::endl;
    this->type = data.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << type << " say auuu" << std::endl;
}