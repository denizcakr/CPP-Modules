
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
    private:
	Brain* brain;

    public:
        Cat();
        ~Cat();
        Cat(const Cat &);
        Cat &operator=(const Cat &);
        void makeSound() const;
        Brain *getBrain();
};

#endif