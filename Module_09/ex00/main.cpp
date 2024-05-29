#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange a;
	if (ac != 2)
		std::cout << "Error: could not open file." << std::endl;
	else
		a.readFiles(av[1], a);
	return (0); 
}