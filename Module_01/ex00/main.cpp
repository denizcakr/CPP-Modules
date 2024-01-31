
#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("Foo");
    zombie1->announce();

    randomChump("Bar");
    delete zombie1;
}