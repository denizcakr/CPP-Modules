
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &);
		Animal &operator=(const Animal &);
		virtual void makeSound() const = 0;
		const std::string getType() const;


};

#endif