
#include "Dog.hpp"

Dog::Dog()
{
    brain = new Brain();
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog::Dog(const Dog &data)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain();
    for (size_t i = 0; i < data.brain->getIdeas()->size() ; i++)
        brain->getIdeas()[i] = data.brain->getIdeas()[i];
    type = data.type;
}

Dog &Dog::operator=(const Dog &data)
{
    std::cout << "Dog copy assigment operator called" << std::endl;
    this->type = data.type;
    for (size_t i = 0; i < data.brain->getIdeas()->size() ; i++)
        brain->getIdeas()[i] = data.brain->getIdeas()[i];
    return *this;
}

void Dog::makeSound() const
{
    std::cout << type << " say Hauuww" << std::endl;
}

Brain *Dog::getBrain()
{
    return brain;
}