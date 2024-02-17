#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;

    Dog x;
    Cat y;
    std::cout << x.getBrain()->getIdeas()[0] << std::endl;
    std::cout << y.getBrain()->getIdeas()[0] << std::endl;

    Dog b;
    Dog a = b;

  
    std::cout << a.getBrain()->getIdeas()[0] << std::endl;

    return 0;
}
