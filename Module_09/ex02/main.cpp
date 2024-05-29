#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe p;
	if (!p.argumentsControl(av, ac))
		return (0);
	p.operation(av,ac);
}