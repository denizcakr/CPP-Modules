
#include "FragTrap.hpp"

int main()
{
    FragTrap a("Deniz ");
    FragTrap b("Eymen ");
    FragTrap guys;

    a.takeDamage(10);
    b.takeDamage(10);
    a.attack("some other other Eymen ");
    for(int i = 0; i < 5; i++)
        b.attack("dude");
    guys.highFivesGuys();
}