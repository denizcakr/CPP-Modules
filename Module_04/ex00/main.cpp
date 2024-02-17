#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    const WrongAnimal* data = new WrongAnimal();
    const WrongAnimal* smellycat = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << smellycat->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    smellycat->makeSound();
    meta->makeSound();
    data->makeSound();

    delete meta;
    delete j;
    delete i;
    delete data;
    delete smellycat;

    
    return 0;
}