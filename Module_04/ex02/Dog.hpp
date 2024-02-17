
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &);
		Dog &operator=(const Dog &);
		void makeSound() const;
		Brain *getBrain();
};

#endif