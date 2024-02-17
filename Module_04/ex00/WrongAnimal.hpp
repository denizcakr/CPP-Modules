
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &);
        WrongAnimal &operator=(const WrongAnimal &data);
        void makeSound() const;
        const std::string getType() const;

};

#endif