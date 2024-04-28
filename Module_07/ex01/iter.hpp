
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>

void iter(T *adr, size_t len, void(*func)(T))
{
	for(size_t i = 0; i < len; i++)
		func(adr[i]);
}

template <typename T>

void printElements(T tmp)
{
	std::cout << tmp << std::endl;
}

#endif