#include "RPN.hpp"

int main(int ac, char **av)
{
    RPN rpn;
    if (ac != 2)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    else
    {
        std::string expression = av[1];
        rpn.calculateRpn(expression);
    }
    return 0;
}