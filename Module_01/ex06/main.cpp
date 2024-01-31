
#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl _harl;
    if(ac > 1)
        _harl.complain(av[1]);
    else
        return 0;
}