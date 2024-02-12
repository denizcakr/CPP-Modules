
#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Deniz ");
    ScavTrap b("Eymen ");
    ScavTrap gate;

    a.takeDamage(10);
    b.takeDamage(10);
    a.attack("some other other Eymen ");
    for(int i = 0; i < 15; i++)
        b.attack("dude");
    gate.guardGate();
}