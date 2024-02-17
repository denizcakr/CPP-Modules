
#include "Cat.hpp"

Cat::Cat()
{
    brain = new Brain();
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat::Cat(const Cat &data)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain();
    for(size_t i = 0; i < data.brain->getIdeas()->size(); i++)
        brain->getIdeas()[i] = data.brain->getIdeas()[i];
    type = data.type;
}

Cat &Cat::operator=(const Cat &data)
{
    std::cout << "Cat copy assigment operator called" << std::endl;
    this->type = data.type;
    for(size_t i = 0; i < data.brain->getIdeas()->size(); i++)
        brain->getIdeas()[i] = data.brain->getIdeas()[i];
    return *this;
}

void Cat::makeSound() const
{
    std::cout << type << " say Miyuw" << std::endl;
}

Brain *Cat::getBrain()
{
    return brain;
}