
#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Deniz ");

    a.takeDamage(10);
    for(int i = 0; i < 15; i++)
        a.attack("dude");
    a.beRepaired(3);
}